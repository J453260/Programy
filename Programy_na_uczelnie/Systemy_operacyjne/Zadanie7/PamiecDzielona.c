#include "PamiecDzielona.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int utworz_pamiec_dzielona(const char *nazwa, size_t rozmiar)
{
    int fd = shm_open(nazwa, O_CREAT | O_RDWR, 0666);
    if (fd == -1)
    {
        perror("shm_open");
        return -1;
    }

    if (ftruncate(fd, rozmiar) == -1)
    {
        perror("ftruncate");
        close(fd);
        return -1;
    }

    return fd;
}

int mapuj_pamiec_dzielona(int fd, size_t rozmiar, void **adres)
{
    void *addr = mmap(NULL, rozmiar, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
    {
        perror("mmap");
        return 0;
    }
    *adres = addr;
    return 1;
}

int odmapuj_pamiec(void *adres, size_t rozmiar)
{
    if (munmap(adres, rozmiar) == -1)
    {
        perror("munmap");
        return 0;
    }
    return 1;
}

int usun_pamiec_dzielona(const char *nazwa)
{
    if (shm_unlink(nazwa) == -1)
    {
        perror("shm_unlink");
        return 0;
    }
    return 1;
}
