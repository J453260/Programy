/*
Autor: Jan Bajor
Data: 03.05.2025
Miejsce: Kraków

Program główny
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include "Semafory.h"
#include "Wspolny.h"

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        printf("Użycie: ./Cw7 Dane1.txt Dane2.txt ./Producent ./Konsument \n");
        exit(EXIT_FAILURE);
    }
    /*
    argv[1] - Dane1.txt
    argv[2] - Dane2.txt
    argv[3] - Producent
    argv[4] - Konsument
    */

    // Usuwanie starych semaforów
    sem_unlink(SEM_PROD);
    sem_unlink(SEM_KONS);
    shm_unlink(SHM_NAME);

    //Pamięć dzielona
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0600);
    if (shm_fd == -1)
    {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(shm_fd, sizeof(SegmentPD)) == -1)
    {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    SegmentPD* wsp = mmap(NULL, sizeof(SegmentPD), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (wsp == MAP_FAILED)
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    memset(wsp, 0, sizeof(SegmentPD));

    //Semafory
    sem_t* prod;
    sem_t* kons;

    if (!sema_open_create(SEM_PROD, O_CREAT | O_EXCL, 0600, NBUF, &prod) ||
            !sema_open_create(SEM_KONS, O_CREAT | O_EXCL, 0600, 0, &kons))
    {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    //Producent
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        execlp(argv[3], argv[3], argv[1], NULL);
        perror("execlp producent");
        exit(EXIT_FAILURE);
    }

    //Konsument
    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        execlp(argv[4], argv[4], argv[2], NULL);
        perror("execlp konsument");
        exit(EXIT_FAILURE);
    }

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    printf("Proces główny: zakończono producenta i konsumenta.\n");

    // Czyszczenie
    munmap(wsp, sizeof(SegmentPD));
    close(shm_fd);
    shm_unlink(SHM_NAME);

    sem_close(prod);
    sem_close(kons);
    sem_unlink(SEM_PROD);
    sem_unlink(SEM_KONS);

    return 0;
}
