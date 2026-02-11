/*
Autor: Jan Bajor
Data: 11.04.2025
Miejsce: Kraków

Program realizuje problem producenta i konsumenta używając funkcji execlp i FIFO.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define FIFO_NAME "mojefifo"

void remove_fifo()
{
    unlink(FIFO_NAME);
}

int main(int argc, char *argv[])
{
    if (argc < 9)
    {
       printf("Błąd: Podano zbyt małą liczbę argumentów.\n");
        exit(1);
    }

    //argv[1] dla Dane1.txt
    //argv[2] dla Dane2.txt
    //argv[3] i [4] dla losowych liczb
    //argv[5] i [6] dla rozmiaru buforów
    //argv[7] i [8] dla execlp

    // Rejestracja funkcji do usunięcia FIFO po zakończeniu
    atexit(remove_fifo);

    const int min = atoi(argv[3]);
    const int max = atoi(argv[4]);
    srand(time(NULL));

    int losowa_liczba1 = rand() % (max - min + 1) + min;
    int losowa_liczba2 = rand() % (max - min + 1) + min;

    // Tworzymy potok FIFO
    if (mkfifo(FIFO_NAME, 0666) == -1)
    {
        perror("Błąd tworzenia FIFO");
        exit(1);
    }

    pid_t pid1 = fork();

    if(pid1 == 0)
    {//argv[8] - konsument
        char losowa_liczba_str2[10];
        char bufor_kons_str[10];
        sprintf(losowa_liczba_str2, "%d", losowa_liczba2);
        sprintf(bufor_kons_str, "%s", argv[5]);
        execlp(argv[8], argv[8], FIFO_NAME, argv[2], losowa_liczba_str2, bufor_kons_str, NULL);
        perror("Błąd execlp (konsument)");
        exit(1);
    }
    //argv[2] - Dane2.txt zapis do pliku
    //argv[4] i [5] - liczba losowa i rozmiar buforu

    pid_t pid2 = fork();
    if(pid2 == 0)
    {
        // argv[7] - Producent
        char losowa_liczba_str[10];
        char bufor_prod_str[10];
        sprintf(losowa_liczba_str, "%d", losowa_liczba1);
        sprintf(bufor_prod_str, "%s", argv[6]);
        execlp(argv[7], argv[7], FIFO_NAME, argv[1], losowa_liczba_str, bufor_prod_str, NULL);
        perror("Błąd execlp (producent)");
        exit(1);
        //argv[1] - Dane1.txt odczyt z pliku
    }

    wait(NULL);
    wait(NULL);
    return 0;
}
