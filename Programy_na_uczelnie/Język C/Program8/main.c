#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funkcje.h"

int main()
{
    char *tekst = "Tekst.";
    FILE *wp;
    wp = fopen("dane.txt", "w");
    if (wp == NULL)
    {
        perror("Nie można otworzyć pliku");
        exit(EXIT_FAILURE);
    }

    int Z1 = WypiszTekst(wp, tekst);
    printf("Program wypisal %d znakow.\n", Z1);
    fclose(wp);

    wp = fopen("dane.txt", "r");
    if (wp == NULL)
    {
        perror("Nie można otworzyć pliku");
        exit(EXIT_FAILURE);
    }

    int max1;
    printf("Ile znakow chcesz przepisac do drugiej tablicy: ");
    scanf("%d", &max1);

    char *tekst2 = malloc((max1 + 1) * sizeof(char));
    if (tekst2 == NULL)
    {
        perror("Błąd alokacji pamięci");
        fclose(wp);
        exit(EXIT_FAILURE);
    }

    int Z2 = CzytajTekst(wp, tekst2, max1);
    tekst2[Z2] = '\0';
    printf("Przepisano %d znakow.\n", Z2);
    fclose(wp);
    free(tekst2);

    char *skad = (char *)malloc(1000 * sizeof(char));
    if (skad == NULL)
    {
        fprintf(stderr, "Błąd alokacji pamięci.\n");
        return 1;  // Zakończenie programu w przypadku błędu
    }

    printf("Wprowadz tekst do kopiowania: ");
    while (getchar() != '\n');

    if (fgets(skad, 1000, stdin) == NULL)
    {
        fprintf(stderr, "Błąd podczas odczytu danych.\n");
        free(skad);  // Zwalniamy pamięć przed zakończeniem programu
        return 1;  // Zakończenie programu w przypadku błędu
    }

    size_t len=strlen(skad);

    if (len > 0 && skad[len - 1] == '\n')
    {
        skad[len - 1] = '\0';  // Zamieniamy znak '\n' na '\0'
    }

    char *dokad = (char *)malloc((1000) * sizeof(char));

    int P = KopiujTekst(skad, dokad, max1);

    printf("Przekopiowano %d znakow.\n", P);
    printf("Przekopiowany tekst: %s\n", dokad);

    free(skad);
    free(dokad);

    FILE *dane2 = fopen("dane2.txt", "r");
    if (dane2 == NULL)
    {
        perror("Nie można otworzyć pliku");
        exit(EXIT_FAILURE);
    }

    char *tekst3 = malloc(10000 * sizeof(char));
    if (tekst3 == NULL)
    {
        perror("Błąd alokacji pamięci");
        fclose(dane2);
        exit(EXIT_FAILURE);
    }

    size_t bytesRead = fread(tekst3, 1, 9999, dane2);
    tekst3[bytesRead] = '\0';
    fclose(dane2);

    printf("Wszystkie znaki: %d\n", WszystkieZnaki(tekst3));
    printf("Czarne znaki: %d\n", CzarneZnaki(tekst3));
    printf("Liczba linii: %d\n", Linie(tekst3));
    printf("Liczba slow: %d\n", Slowa(tekst3));

    free(tekst3);
    return 0;
}
