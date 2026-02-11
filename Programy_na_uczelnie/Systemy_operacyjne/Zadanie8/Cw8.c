/*
Autor: Jan Bajor
Data: 18.05.2025
Miejsce: Kraków

kod główny z którego są wywoływani klienci i serwer
(klientów i serwer można również wywołać z Makefile z użyciem polecenia xterm)
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    /*
     argv[1] - ./serwer
     argv[2] - ./klient
     argv[3] - liczba klientów
     argv[4] - min_sleep
     argv[5] - max_sleep
    */
    if (argc < 6)
    {
        fprintf(stderr, "Użycie: %s ./serwer ./klient liczba_klientow min_sleep max_sleep\n", argv[0]);
        return 1;
    }

    char *server_bin = argv[1];
    char *client_bin = argv[2];
    int num_clients = atoi(argv[3]);
    char *min_sleep = argv[4];
    char *max_sleep = argv[5];

    srand(time(NULL));

    // 1. Uruchamiamy serwer w nowym xterm
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork serwer");
        exit(1);
    }
    if (pid == 0)
    {
        execlp("xterm", "xterm",
               "-hold",
               "-title", "SERWER",
               "-e", server_bin, min_sleep, max_sleep,
               (char *)NULL);
        perror("execlp xterm serwer");
        exit(1);
    }

    // dajemy serwerowi chwilę, by się wystartował
    sleep(1);

    // 2. Uruchamiamy klientów w osobnych xterm
    pid_t *clients = calloc(num_clients, sizeof(pid_t));
    for (int i = 0; i < num_clients; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("fork klient");
            exit(1);
        }
        if (pid == 0)
        {

            char title[32];
            snprintf(title, sizeof(title), "KLIENT%d", i+1);

            execlp("xterm", "xterm",
                   "-hold",
                   "-title", title,
                   "-e", client_bin,
                   min_sleep, max_sleep,
                   (char *)NULL);
            perror("execlp xterm klient");
            exit(1);
        }
        clients[i] = pid;
        sleep(1);
    }

    // 3. Czekamy na zakończenie wszystkich klientów
    for (int i = 0; i < num_clients; i++)
    {
        waitpid(clients[i], NULL, 0);
    }

    // 4. Po kliencie zabijamy serwer SIGINT, czekamy na niego
    kill(pid, SIGINT);
    waitpid(pid, NULL, 0);

    free(clients);
    return 0;
}
