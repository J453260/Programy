#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "Semafory.h"

int main(int argc, char *argv[])
{
    if (argc < 7)
    {
        printf("Użycie: %s <plik> <min> <max> <nazwa_semafora> <program_do_uruchomienia> <ilość inkrementacji>\n", argv[0]);
        return 1;
    }

    char nazwa_sem[256];
    snprintf(nazwa_sem, sizeof(nazwa_sem), "/%s", argv[4]);

    // Stworzenie semafora
    sem_t *sem = sema_open(nazwa_sem, O_CREAT | O_EXCL, 0600, 1);
    if (sem == NULL)
    {
        perror("sem_open");
        return 1;
    }
    sema_close(sem);

    // Tworzenie 10 procesów potomnych
    int n = atoi(argv[6]);
    for (int i = 0; i < n; i++)
    {
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork");
            return 1;
        }
        else if (pid == 0)
        {
            execlp(argv[5], argv[5], argv[1], argv[2], argv[3], nazwa_sem, NULL);
            perror("execlp");
            exit(1); // Kod ten nigdy nie zostanie wywołany, jeżeli execlp się powiedzie
        }
    }

    // Oczekiwanie na wszystkie procesy
    for (int i = 0; i < n; i++)
    {
        wait(NULL);
    }

    // Czyszczenie semafora po zakończeniu
    sema_unlink(nazwa_sem);

    return 0;
}
