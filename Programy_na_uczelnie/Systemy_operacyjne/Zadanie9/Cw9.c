/*
Autor: Jan Bajor
Data: 25.05.2025
Miejsce: Kraków

Program realizujący zagadnienie wzajemnego wykluczania wątków.
Zawiera strukturę "DaneWatku" czyli dane każdego wątku.
Najpierw jest tworzony mutex.
Potem każdemu wątkowi są przypisywane dane.
Następnie wywoływna jest funkcja watek_funkcja, w której każdy wątek
przechodzi liczbę razy przez sekcję prywatną i krytczną ile wynosi liczba cykle.
W trakcie działania funkcji inkremetowany jest licznik.
Po zakończeniu pętli uruchamiana jest druga pętla czekająca na zakończenie wątków.
Na końcu nastepuje usunięcie muteksa i zwolnienie pamięci.
*/

#define _POSIX_C_SOURCE 200809L //dla mutexów
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#define XMAX 60
#define YMAX 25

//dane każdego wątku przekazywane później do funkcji
typedef struct
{
    int id;
    int cykle;
    int min;  // dla losowego czasu spania
    int max;
} DaneWatku;

pthread_mutex_t muteks;
int licznik = 0;
int liczbaWatkow;

//funkcja losująca czas spania
void spanie(int min, int max)
{
    int s = min + rand() % (max - min + 1);
    sleep(s);
}

//ta funkcja okresla gdzie tekst ma się pojawić na ekranie
void gotoxy(unsigned x, unsigned y)
{
    printf("\033[%d;%dH\033[2K", y, x);
    fflush(stdout);
}

void *watek_funkcja(void *arg)
{
    DaneWatku *dane = (DaneWatku *)arg;

    for (int i = 0; i < dane->cykle; ++i)
    {
        int wiersz = dane->id + 1;

        // Sekcja prywatna
        gotoxy(1, wiersz);
        printf("Wątek %d: sekcja prywatna (%d)", dane->id, i + 1);
        fflush(stdout);

        //spanie
        spanie(dane->min, dane->max);

        // Sekcja krytyczna
        //zablokowanie mutexa, żaden inny wątek nie może korzystać z sekcji krytycznej
        int err = pthread_mutex_lock(&muteks);
        if (err != 0)
        {
            fprintf(stderr, "Błąd pthread_mutex_lock: %s\n", strerror(err));
            exit(EXIT_FAILURE);
        }

        gotoxy(40, wiersz);
        int temp = licznik;

        //spanie tutaj
        spanie(dane->min, dane->max);

        licznik = temp + 1;
        printf("Wątek %d: sekcja krytyczna (%d), licznik = %d", dane->id, i + 1, licznik);
        fflush(stdout);

        err = pthread_mutex_unlock(&muteks); //odblokowanie
        if (err != 0)
        {
            fprintf(stderr, "Błąd pthread_mutex_unlock: %s\n", strerror(err));
            exit(EXIT_FAILURE);
        }

        //tutaj też
        spanie(dane->min, dane->max);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        fprintf(stderr, "Użycie: %s <liczba_wątków> <liczba_cykli> <min> <max>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /*
    argv[0] - cw8
    argv[1] - liczba wątków
    argv[2] - cykle
    argv[3] - min
    argv[4] - max
    */

    liczbaWatkow = atoi(argv[1]);
    int cykle = atoi(argv[2]);
    if (liczbaWatkow <= 0 || cykle <= 0)
    {
        fprintf(stderr, "Podaj liczby większe od zera.\n");
        return EXIT_FAILURE;
    }

    srand(time(NULL));
    system("clear"); //czyszczenie ekranu

    printf(">>> Adres muteksu: %p\n", (void *)&muteks);

    //zawiera liczbę wątków, potrzebną później do tworzenia wątków
    pthread_t *watki = malloc(sizeof(pthread_t) * liczbaWatkow);

    //tworzy tablicę struktur z danymi dla każdego wątku
    DaneWatku *dane = malloc(sizeof(DaneWatku) * liczbaWatkow);

    int min = atoi(argv[3]);
    int max = atoi(argv[4]);

    int err = pthread_mutex_init(&muteks, NULL); //inicjalizacja mutexa
    if (err != 0)
    {
        fprintf(stderr, "Błąd pthread_mutex_init: %s\n", strerror(err));
        return EXIT_FAILURE;
    }

    //pętla do tworzenia wątków
    for (int i = 0; i < liczbaWatkow; ++i)
    {
        dane[i].id = i + 1;
        dane[i].cykle = cykle;
        err = pthread_create(&watki[i], NULL, watek_funkcja, &dane[i]);
        if (err != 0)
        {
            fprintf(stderr, "Błąd pthread_create: %s\n", strerror(err));
            return EXIT_FAILURE;
        }
        printf("Utworzono wątek %d: pthread_t = %lu\n", i + 1, watki[i]);
    }

    //pętla do czekania na zakończenie wszystkich wątków
    for (int i = 0; i < liczbaWatkow; ++i)
    {
        dane[i].id = i + 1;
        dane[i].cykle = cykle;
        dane[i].min = min;
        dane[i].max = max;

        err = pthread_join(watki[i], NULL);
        if (err != 0)
        {
            fprintf(stderr, "Błąd pthread_join: %s\n", strerror(err));
            return EXIT_FAILURE;
        }
    }

    //niszczenie mutexa
    err = pthread_mutex_destroy(&muteks);
    if (err != 0)
    {
        fprintf(stderr, "Błąd pthread_mutex_destroy: %s\n", strerror(err));
        return EXIT_FAILURE;
    }

    gotoxy(0, YMAX + 1);
    printf("\nKoniec programu. Wartość licznika = %d (oczekiwano: %d)\n",
           licznik, liczbaWatkow * cykle);

    free(watki);
    free(dane);
    return 0;
}
