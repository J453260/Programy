#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //argv[1] dla Dane1.txt
    //argv[2] dla Dane2.txt
    //argv[3] dla min
    //argv[4] dla max

    if(argc<5)
    {
        perror("Podano zbyt małą liczbę argumentów.");
        exit(1);
    }

    const int min = atoi(argv[3]), max = atoi(argv[4]);
    srand(time(NULL));
    int losowa_liczba1 = rand() % (max - min + 1) + min;
    int losowa_liczba2 = rand() % (max - min + 1) + min;
    printf("1 losowa liczba: %d\n", losowa_liczba1);
    printf("2 losowa liczba: %d\n", losowa_liczba2);
    FILE *plik1 = fopen(argv[1], "r");
    FILE *plik2 = fopen(argv[2], "w");
    if (plik1 == NULL)
    {
        perror("Błąd otwierania pliku");
        exit(1);
    }

    if (plik2 == NULL)
    {
        perror("Błąd otwierania pliku");
        exit(1);
    }
    int fd[2];  // deskryptory potoku: fd[0] - odczyt, fd[1] - zapis
    pid_t pid;

    if (pipe(fd) == -1)
    {
        perror("Błąd tworzenia potoku");
        exit(1);
    }

    pid = fork();
    switch(pid)
    {
    case -1:
        perror("Błąd fork");
        exit(1);

    case 0://proces potomny = konsument
        close(fd[1]); // Zamykamy niepotrzebny deskryptor zapisu

        // Konsument odczytuje dane z potoku
        char bufor1[100];
        int n1;
        while ((n1 = read(fd[0], bufor1, sizeof(bufor1))) > 0)
        {
            bufor1[n1] = '\0';
            fwrite(bufor1, 1, n1, plik2);

            // Simulacja czasu pracy
            sleep(losowa_liczba1);

            // Wyświetlanie komunikatu na ekranie
            const char t1[] = "Konsument odebrał: ";
            const char newline = '\n';
            write(1, t1, sizeof(t1) - 1);
            write(1, bufor1, strlen(bufor1));
            write(1, &newline, 1);
            char komunikat[50];
            int dlugosc = snprintf(komunikat, sizeof(komunikat), "Konsument odebrał %d bajtów\n", n1);
            write(1, komunikat, dlugosc);
        }

        close(fd[0]);  // Zamykamy odczyt potoku
        break;

    default: //proces macierzysty = producent
        close(fd[0]); // Zamykamy niepotrzebny deskryptor odczytu

        // Producent odczytuje dane z pliku i wysyła do potoku
        char bufor2[100];
        int n2;
        while ((n2 = fread(bufor2, 1, sizeof(bufor2) - 1, plik1)) > 0)
        {
            bufor2[n2] = '\0';
            write(fd[1], bufor2, n2);

            // Symulacja czasu pracy
            sleep(losowa_liczba2);

            // Wyświetlanie komunikatu na ekranie
            const char *t2 = "Producent dodał dane do bufora.\n";
            int liczbaB2 = strlen(t2);
            write(1, t2, liczbaB2);
            char komunikat[50];
            int dlugosc = snprintf(komunikat, sizeof(komunikat), "Producent odczytał %d bajtów\n", n2);
            write(1, komunikat, dlugosc);
        }

        close(fd[1]);  // Zamykamy zapis do potoku
        break;
    }

    fclose(plik1);
    fclose(plik2);
    return 0;
}
