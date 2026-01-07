#include <stdio.h>
#include <stdlib.h>

#define NC 10 // Rozmiar tablicy cyfr

int main()
{
    FILE *wejscie, *wyjscie;
    int c;                // Kod ASCII znaku
    int biale = 0;        // Licznik białych znaków
    int inne = 0;         // Licznik innych znaków
    int cyfry[NC] = {0};  // Liczniki cyfr

    // Otwarcie pliku wejściowego
    wejscie = fopen("wejscie.txt", "r");
    if (wejscie == NULL)
    {
        perror("Blad otwarcia pliku wejsciowego");
        exit(EXIT_FAILURE);
    }

    // Otwarcie pliku wyjściowego
    wyjscie = fopen("wyjscie.txt", "w");
    if (wyjscie == NULL)
    {
        perror("Blad otwarcia pliku wyjsciowego");
        fclose(wejscie);
        exit(EXIT_FAILURE);
    }

    // Przetwarzanie danych z pliku wejściowego
    while ( (c = fgetc(wejscie)) != EOF ) // wczytanie znaku
    {
        fputc(c, wyjscie);
        switch (c)  // rozpoznanie znaku
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            cyfry[c - '0']++; // zliczanie cyfr
            break;
        case ' ':
        case '\n':
        case '\t':
            biale++; // zliczanie bialych znakow
            break;
        default:
            inne++; // zliczanie innych znakow
            break;
        }
    } // switch

    // Zapis statystyk do pliku wynikowego
    fprintf(wyjscie, "\nStatystyki:\n");
    fprintf(wyjscie, "Cyfry:\n");
    for (int i = 0; i < NC; i++)
    {
        fprintf(wyjscie, "\t%c: %d\n", '0' + i, cyfry[i]);
    }
    fprintf(wyjscie, "Białe znaki: %d\nInne znaki: %d\n", biale, inne);

    // Zamknięcie plików
    fclose(wejscie);
    fclose(wyjscie);

    printf("Przetwarzanie zakonczone. Wyniki zapisano w 'wyjscie.txt'.\n");
    return 0;
}
