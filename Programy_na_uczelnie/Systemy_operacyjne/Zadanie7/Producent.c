#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "Semafory.h"
#include "Wspolny.h"
#include "PamiecDzielona.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Brak pliku źródłowego.\n");
        exit(EXIT_FAILURE);
    }

    // 1) Otwiera plik źródłowy do odczytu
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open producent");
        exit(EXIT_FAILURE);
    }

    // 2) Otwiera istniejący segment pamięci dzielonej
    int shm_fd = shm_open(SHM_NAME, O_RDWR, 0);
    if (shm_fd == -1)
    {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    SegmentPD* wsp;
    if (!mapuj_pamiec_dzielona(shm_fd, sizeof(SegmentPD), (void**)&wsp))
    {
        fprintf(stderr, "Błąd mapowania pamięci dzielonej w Producent\n");
        exit(EXIT_FAILURE);
    }

    if (wsp == MAP_FAILED)
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // 3) Otwiera istniejące semafory
    sem_t* sem_prod;
    sem_t* sem_kons;
    if (!sema_open_existing(SEM_PROD, &sem_prod) ||
            !sema_open_existing(SEM_KONS, &sem_kons))
    {
        fprintf(stderr, "Błąd otwierania semaforów\n");
        exit(EXIT_FAILURE);
    }

    // 4) Pętla produkcji: czyta znak po znaku i wstawiaj do bufora
    char znak;
    while (read(fd, &znak, 1) == 1)
    {
        if (!sema_wait(sem_prod))
        {
            fprintf(stderr, "sema_wait prod error\n");
            break;
        }

        wsp->bufor[wsp->wstaw].element[0] = znak;
        wsp->bufor[wsp->wstaw].element[1] = '\0';
        printf("Producent: Wstawiam '%c' na pozycję %d\n",
               znak, wsp->wstaw);

        wsp->wstaw = (wsp->wstaw + 1) % NBUF;

        if (!sema_post(sem_kons))        // V(sem_kons)
        {
            fprintf(stderr, "sema_post kons error\n");
            break;
        }
    }

    // 5) Wstawienie znaków EOF (sygnał zakończenia)
    for (int i = 0; i < NBUF; i++)
    {
        sema_wait(sem_prod);
        wsp->bufor[wsp->wstaw].element[0] = EOF;
        wsp->bufor[wsp->wstaw].element[1] = '\0';
        wsp->wstaw = (wsp->wstaw + 1) % NBUF;
        sema_post(sem_kons);
    }

    // 6) Sprzątanie
    odmapuj_pamiec(wsp, sizeof(SegmentPD));
    close(shm_fd);
    close(fd);

    sema_close(sem_prod);
    sema_close(sem_kons);

    return 0;
}
