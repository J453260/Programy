/*
Autor: Jan Bajor
Data: 02.06.2025
Miejsce: Kraków

Kod zawiera wzajemne wykluczanie wątków z użyciem algorytmu piekarni.
Algorytm piekarni znajduje się w funkcji "wątek funkcja".
Na początku każdemu wątkowi, który wszedł do funkcji jest przydzielany numer.
Każdy wątek przechodzi przez sekcję krytyczną "cykle" razy,
ale tylko jeden na raz, inkrementując licznik z każdą iteracją.
*/

//#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <time.h>

int n;                  // liczba wątków
volatile int *numer;             // tablica numerów
volatile bool *wybieranie;       // tablica wybierania (czy dany wątek wybiera numer)
int licznik = 0;        // współdzielony licznik - inkrementowany w sekcji krytycznej

typedef struct
{
    int id;
    int cykle;
    int min;
    int max;
} DaneWatku;

//funkcja losująca czas spania
void spanie(int min, int max)
{
    int s = min + rand() % (max - min + 1);
    sleep(s);
}

//ta funkcja okresla gdzie tekst ma się pojawić na ekranie
void gotoxy(int x, int y)
{
    printf("\033[%d;%dH\033[2K", y, x);
    fflush(stdout);
}

void *watek_funkcja(void *arg)
{
    DaneWatku *d = (DaneWatku *)arg;
    int i = d->id;

    for (int iter = 0; iter < d->cykle; ++iter)
    {
        // === Sekcja prywatna (dowolna praca lokalna) ===
        gotoxy(1, i+1);
        printf("Wątek %d: sekcja prywatna (%d)        ", i, iter+1);
        fflush(stdout);
        spanie(d->min, d->max);

        // === Sekcja wejściowa (Alg. piekarni) ===
        wybieranie[i] = true;
        int maks = 0;
        for (int k = 0; k < n; ++k)
            if (numer[k] > maks)
                maks = numer[k];
        numer[i] = maks + 1;
        wybieranie[i] = false;

        for (int j = 0; j < n; ++j)
        {
            // czekaj, aż wątek j przestanie wybierać numer
            while (wybieranie[j]) {/* czekanie */}
            // czekaj, aż j nie będzie rywalizował lub ma mniejszy priorytet
            while (numer[j] != 0 &&
                    ( numer[j] < numer[i] ||
                      (numer[j] == numer[i] && j < i)
                    )
                  )
            {/* czekanie */}
        }

        // === Sekcja krytyczna ===
        gotoxy(50, i+1);
        int temp = licznik;
        spanie(d->min, d->max);
        licznik = temp + 1;
        printf("Wątek %d: sekcja krytyczna (%d), licznik = %d",
               i, iter+1, licznik);
        fflush(stdout);

        // === Sekcja wyjściowa ===
        numer[i] = 0;

        //spanie
        spanie(d->min, d->max);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        fprintf(stderr, "Użycie: %s <liczbaWatkow> <cykle> <min> <max>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);
    int cykle = atoi(argv[2]);
    int min = atoi(argv[3]);
    int max = atoi(argv[4]);
    srand(time(NULL));
    system("clear"); //czyszczenie ekranu

    // Alokacja tablic współdzielonych
    wybieranie = calloc(n, sizeof(bool));
    numer = calloc(n, sizeof(int));
    pthread_t *watki = calloc(n, sizeof(pthread_t));
    DaneWatku *dane  = calloc(n, sizeof(DaneWatku));

    for (int i = 0; i < n; ++i)
    {
        dane[i].id = i;
        dane[i].cykle = cykle;
        dane[i].min = min;
        dane[i].max = max;
        pthread_create(&watki[i], NULL, watek_funkcja, &dane[i]);
    }


    for (int i = 0; i < n; ++i)
    {
        pthread_join(watki[i], NULL);
    }

    gotoxy(0, n + 2);
    printf("\nKoniec programu. Wartość licznika = %d (oczekiwano: %d)\n",
           licznik, n * cykle);

    free(wybieranie);
    free(numer);
    free(watki);
    free(dane);
    return 0;
}
