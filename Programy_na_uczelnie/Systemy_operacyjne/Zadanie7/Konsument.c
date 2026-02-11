#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/stat.h>
#include "Semafory.h"
#include "Wspolny.h"
#include "PamiecDzielona.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Brak pliku docelowego.\n");
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open konsument");
        exit(EXIT_FAILURE);
    }

    int shm_fd = shm_open(SHM_NAME, O_RDWR, 0600);
    SegmentPD* wsp;
    if (!mapuj_pamiec_dzielona(shm_fd, sizeof(SegmentPD), (void**)&wsp))
    {
        fprintf(stderr, "Błąd mapowania pamięci dzielonej w Producent\n");
        exit(EXIT_FAILURE);
    }

    sem_t* prod;
    sem_t* kons;
    if (!sema_open_existing(SEM_PROD, &prod))
    {
        perror("sema_open_existing prod");
        exit(EXIT_FAILURE);
    }

    if (!sema_open_existing(SEM_KONS, &kons))
    {
        perror("sema_open_existing kons");
        exit(EXIT_FAILURE);
    }

    int koniec = 0;
    while (!koniec)
    {
        if (!sema_wait(kons))
        {
            perror("sema_wait");
            exit(EXIT_FAILURE);
        }

        char znak = wsp->bufor[wsp->wyjmij].element[0];
        if (znak == EOF)
        {
            koniec = 1;
        }
        else
        {
            write(fd, &znak, 1);
            printf("Konsument: Czytam '%c' z pozycji %d\n", znak, wsp->wyjmij);
        }

        wsp->wyjmij = (wsp->wyjmij + 1) % NBUF;

        if (!sema_post(prod))
        {
            perror("sema_post");
            exit(EXIT_FAILURE);
        }
    }

    odmapuj_pamiec(wsp, sizeof(SegmentPD));
    close(shm_fd);
    close(fd);

    // Użycie funkcji sema_close zamiast sem_close
    if (!sema_close(prod))
    {
        perror("sema_close prod");
        exit(EXIT_FAILURE);
    }

    if (!sema_close(kons))
    {
        perror("sema_close kons");
        exit(EXIT_FAILURE);
    }

    return 0;
}
