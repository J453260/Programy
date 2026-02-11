/*
serwer
odbiera zapytanie od klientów i wysyła im wynik
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#include "mqhelper.h"

#ifndef MAX_KLIENCI
#define MAX_KLIENCI 2
#endif

mqd_t server_qd;
int zakonczonych_klientow = 0;

void random_sleep(int min_s, int max_s)
{
    int s = min_s + rand() % (max_s - min_s + 1);
    sleep(s);
}

void cleanup()
{
    printf("[Serwer] Czyszczenie: zamykam i usuwam kolejkę %s\n", SERVER_QUEUE_NAME);
    CheckError(!CloseQueue(server_qd), "mq_close");
    CheckError(!RemoveQueue(SERVER_QUEUE_NAME), "mq_unlink");
}

void sigint_handler(int sig)
{
    (void)sig;
    printf("\n[Serwer] Otrzymano SIGINT — kończę.\n");
    cleanup();
    exit(0);
}

int wykonaj_dzialanie(const char *input, char *output)
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
    srand(time(NULL));

    CheckError(!RemoveQueue(SERVER_QUEUE_NAME), "mq_unlink");
    CheckError(!CreateQueue(SERVER_QUEUE_NAME, &default_attr, &server_qd), "mq_open");

    struct mq_attr attr;
    CheckError(mq_getattr(server_qd, &attr) == -1, "mq_getattr");

    printf("[Serwer] Utworzono kolejkę %s (maxmsg=%ld, msgsize=%ld)\n",
           SERVER_QUEUE_NAME, attr.mq_maxmsg, attr.mq_msgsize);

    while (1)
    {
        char *buffer = malloc(attr.mq_msgsize + 1);
        CheckError(buffer == NULL, "malloc");

        ssize_t len = ReceiveMessage(server_qd, buffer, attr.mq_msgsize);
        CheckError(len < 0, "mq_receive");
        buffer[len] = '\0';
        printf("[Serwer] Odebrano: \"%s\"\n", buffer);

        random_sleep(min, max);

        char client_q[64], expr[128], result[64];
        if (sscanf(buffer, "%63s %127[^\n]", client_q, expr) < 1)
        {
            fprintf(stderr, "[Serwer] Błędny format: \"%s\"\n", buffer);
            free(buffer);
            continue;
        }

        expr[strcspn(expr, "\n")] = '\0';

        if (strlen(expr) == 0)
        {
            printf("[Serwer] Klient %s zakończył działanie.\n", client_q);
            zakonczonych_klientow++;
            free(buffer);
            if (zakonczonych_klientow >= MAX_KLIENCI)
            {
                printf("[Serwer] Wszyscy klienci zakończyli. Kończę.\n");
                break;
            }
            continue;
        }

        int status = wykonaj_dzialanie(expr, result);
        if (status == -1) strcpy(result, "Błąd formatu");
        else if (status == -2) strcpy(result, "Dzielenie przez zero");

        printf("[Serwer] Wynik dla %s: %s\n", client_q, result);

        mqd_t client_qd;
        if (OpenQueue(client_q, O_WRONLY, &client_qd))
        {
            SendMessage(client_qd, result);
            CloseQueue(client_qd);
        }
        else
        {
            perror("[Serwer] Błąd otwarcia kolejki klienta");
        }

        free(buffer);
    }

    cleanup();
    return 0;
}
