/*
klient
wysyła zapytanie do serwera i oczekuje na odpowiedź
również oblicza lokalnie porównując z serwerem
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#include "mqhelper.h"

#define MAX_EXPR 128

char client_queue_name[64];
mqd_t client_qd;

void random_sleep(int min_s, int max_s)
{
    int s = min_s + rand() % (max_s - min_s + 1);
    sleep(s);
}

void cleanup()
{
    printf("[Klient] Czyszczenie: zamykam i usuwam kolejkę %s\n", client_queue_name);
    CheckError(!CloseQueue(client_qd), "mq_close");
    CheckError(!RemoveQueue(client_queue_name), "mq_unlink");
}

void sigint_handler(int sig)
{
    (void)sig;
    printf("\n[Klient] Otrzymano SIGINT — kończę.\n");
    cleanup();
    exit(0);
}

int wykonaj_lokalnie(const char *input, char *output)
{
    int a, b;
    char op;
    if (sscanf(input, "%d %c %d", &a, &op, &b) != 3) return -1;
    switch (op)
    {
    case '+':
        sprintf(output, "%d", a + b);
        break;
    case '-':
        sprintf(output, "%d", a - b);
        break;
    case '*':
        sprintf(output, "%d", a * b);
        break;
    case '/':
        if (b == 0) return -2;
        sprintf(output, "%d", a / b);
        break;
    default:
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Użycie: %s MIN_SLEEP MAX_SLEEP\n", argv[0]);
        exit(1);
    }

    int min = atoi(argv[1]), max = atoi(argv[2]);

    signal(SIGINT, sigint_handler);
    atexit(cleanup);
    srand(time(NULL) ^ getpid());

    snprintf(client_queue_name, sizeof(client_queue_name), "/klient%d", getpid());
    CheckError(!RemoveQueue(client_queue_name), "mq_unlink");
    CheckError(!CreateQueue(client_queue_name, &default_attr, &client_qd), "mq_open");

    while (1)
    {
        printf("[Klient] Podaj działanie (np. 2 + 2): ");
        fflush(stdout);

        char expr[MAX_EXPR];
        if (fgets(expr, sizeof(expr), stdin) == NULL)
        {
            printf("[Klient] Wykryto Ctrl+D — kończenie.\n");
            char msg[DEFAULT_MQ_MSGSIZE];
            snprintf(msg, sizeof(msg), "%s ", client_queue_name);

            mqd_t server_qd;
            if (OpenQueue(SERVER_QUEUE_NAME, O_WRONLY, &server_qd))
            {
                SendMessage(server_qd, msg);
                CloseQueue(server_qd);
            }
            break;
        }

        expr[strcspn(expr, "\n")] = '\0';

        char msg[DEFAULT_MQ_MSGSIZE];
        snprintf(msg, sizeof(msg), "%s %s", client_queue_name, expr);

        mqd_t server_qd;
        CheckError(!OpenQueue(SERVER_QUEUE_NAME, O_WRONLY, &server_qd), "mq_open");
        CheckError(!SendMessage(server_qd, msg), "mq_send");
        CloseQueue(server_qd);

        random_sleep(min, max);

        struct mq_attr cattr;
        CheckError(mq_getattr(client_qd, &cattr) == -1, "mq_getattr");

        char *response = malloc(cattr.mq_msgsize + 1);
        CheckError(response == NULL, "malloc");

        ssize_t len = ReceiveMessage(client_qd, response, cattr.mq_msgsize);
        CheckError(len < 0, "mq_receive");
        response[len] = '\0';

        char expected[64];
        int st = wykonaj_lokalnie(expr, expected);
        if (st == 0 && strcmp(response, expected) == 0)
            printf("[Klient] Zgodny wynik: %s\n\n", response);
        else if (st == 0)
            printf("[Klient] Sprzeczność! Serwer: %s, lokalnie: %s\n\n", response, expected);
        else
            printf("[Klient] Serwer odpowiedział: %s\n\n", response);

        free(response);
    }

    return 0;
}
