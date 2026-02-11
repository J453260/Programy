#ifndef PAMIECDZIELONA_H
#define PAMIECDZIELONA_H

#include <stddef.h>

int utworz_pamiec_dzielona(const char *nazwa, size_t rozmiar);
int mapuj_pamiec_dzielona(int fd, size_t rozmiar, void **adres);
int usun_pamiec_dzielona(const char *nazwa);
int odmapuj_pamiec(void *adres, size_t rozmiar);

#endif
