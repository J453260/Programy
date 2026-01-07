#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    // Sprawdzenie liczby argumentów
    assert(argc == 3 && "Niepoprawna ilosc argumentow.\n");

    // Otwieranie pliku wejściowego
    FILE *wp = fopen(argv[1], "r");
    assert(wp != NULL && "Nie mozna otworzyc pliku wejsciowego.");

    // Wczytanie liczb zespolonych
    double re1, im1, re2, im2;
    int wynik;

    wynik = fscanf(wp, "%lg %lg", &re1, &im1);
    assert(wynik == 2 && "Nie udalo sie zczytac pierwszej liczby zespolonej.");

    wynik = fscanf(wp, "%lg %lg", &re2, &im2);
    assert(wynik == 2 && "Nie udalo sie zczytac drugiej liczby zespolonej.");

    // Tworzenie liczb zespolonych
    double complex z1 = re1 + im1 * I;
    double complex z2 = re2 + im2 * I;

    // Wyświetlanie wczytanych liczb
    printf("Wczytano 1 liczbe zespolona: %.2f + %.2fi\n", creal(z1), cimag(z1));
    printf("Wczytano 2 liczbe zespolona: %.2f + %.2fi\n", creal(z2), cimag(z2));

    // Sprzężenie zespolone i inne właściwości
    double complex z1_conj = conj(z1);
    printf("Sprzezenie 1 liczby zespolonej: %.2f + %.2fi\n", creal(z1_conj), cimag(z1_conj));
    printf("Modul 1 liczby zespolonej: %.2f\n", cabs(z1));
    printf("Faza 1 liczby zespolonej: %.2f radianow\n", carg(z1));

    // Operacje na liczbach zespolonych
    double complex suma = z1 + z2;
    double complex roznica = z1 - z2;
    double complex iloczyn = z1 * z2;
    double complex iloraz = z1 / z2;

    // Wyświetlanie wyników
    printf("Suma: %.2f + %.2fi\n", creal(suma), cimag(suma));
    printf("Roznica: %.2f + %.2fi\n", creal(roznica), cimag(roznica));
    printf("Iloczyn: %.2f + %.2fi\n", creal(iloczyn), cimag(iloczyn));
    printf("Iloraz: %.2f + %.2fi\n", creal(iloraz), cimag(iloraz));

    // Zamykanie pliku wejściowego
    fclose(wp);

    // Otwieranie pliku wyjściowego
    FILE *wp2 = fopen(argv[2], "w");
    assert(wp2 != NULL && "Nie mozna otworzyc pliku wyjsciowego.");

    // Zapis pierwszej liczby zespolonej do pliku
    int zapis = fprintf(wp2, "%.2f %.2f\n", creal(z1), cimag(z1));
    assert(zapis > 0 && "Nie udalo sie zapisac liczby zespolonej do pliku.");

    printf("Pierwsza liczba zespolona zostala zapisana do pliku 'wynik.txt'.\n");

    // Zamykanie pliku wyjściowego
    fclose(wp2);

    return 0;
}
