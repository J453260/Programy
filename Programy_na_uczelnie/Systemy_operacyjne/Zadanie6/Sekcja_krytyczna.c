#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include "Semafory.h"

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        fprintf(stderr, "Użycie: %s <plik> <min> <max> <semafor>\n", argv[0]);
        return 1;
    }

    char *plik = argv[1];
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);
    char *nazwa_sem = argv[4];

    srand(getpid());
    int czas = rand() % (max - min + 1) + min;

    // Otwarcie pliku
    int fd_read = open(plik, O_RDONLY | O_CREAT, 0600);
    if (fd_read == -1)
    {
        perror("open");
        return 1;
    }

    // Otwieranie semafora
    sem_t *sem = sema_open_existing(nazwa_sem);
    if (!sem)
    {
        perror("sem_open_existing");
        close(fd_read);
        return 1;
    }

    if (sem_wait(sem) == -1)
    {
        perror("sem_wait");
        sema_close(sem);
        close(fd_read);
        return 1;
    }

    int liczba;

    lseek(fd_read, 0, SEEK_SET);
    char bufor[32]; // wystarczająco duży dla liczby jako tekst
    char tekst[32];
    ssize_t bytes_read;

    lseek(fd_read, 0, SEEK_SET);
    bytes_read = read(fd_read, bufor, sizeof(bufor) - 1);
    if (bytes_read <= 0)
    {
        if (bytes_read == 0)  // Plik pusty
        {
            liczba = 0;
        }
        else
        {
            perror("read");
            sem_post(sem);
            sema_close(sem);
            close(fd_read);
            return 1;
        }
    }
    else
    {
        bufor[bytes_read] = '\0'; // zakończenie tekstu
        liczba = atoi(bufor);
    }

    close(fd_read);

    printf("[PID %d] Przed: %d\n", getpid(), liczba);

    sleep(czas);

    // Zwiększenie liczby
    liczba++;

    int fd_write = open(plik, O_WRONLY, 0600);
    if (fd_write == -1)
    {
        perror("open");
        return 1;
    }

    if (lseek(fd_write, 0, SEEK_SET) == -1) // Ustawienie wskaźnika pliku na początek
    {
        perror("lseek");
        sem_post(sem);
        sema_close(sem);
        close(fd_write);
        return 1;
    }

    sprintf(tekst, "%d", liczba);

    if (write(fd_write, tekst, strlen(tekst)) != (ssize_t)strlen(tekst))
    {
        perror("write");
        sem_post(sem);
        sema_close(sem);
        close(fd_write);
        return 1;
    }

    printf("[PID %d] Po: %d\n", getpid(), liczba);

    sem_post(sem);
    sema_close(sem);
    close(fd_write);

    return 0;
}
