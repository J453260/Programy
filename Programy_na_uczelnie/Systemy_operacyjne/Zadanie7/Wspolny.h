#ifndef WSPOLNY_H
#define WSPOLNY_H

#define NELE 20 // Rozmiar elementu bufora (jednostki towaru) w bajtach
#define NBUF 5 // Liczba elementow bufora

// Nazwy pamięci dzielonej i semaforów POSIX
#define SHM_NAME "/segment_pd"
#define SEM_PROD "/sem_prod"
#define SEM_KONS "/sem_kons"

typedef struct
{
    char element[NELE];
} Towar;

typedef struct
{
    Towar bufor[NBUF]; // Wspolny bufor danych
    int wstaw, wyjmij; // Pozycje wstawiania i wyjmowania z bufora
} SegmentPD; // Segment pamieci dzielonej

#endif // WSPOLNY_H
