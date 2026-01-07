#include <stdio.h>
#include <stdlib.h>
/*
 Program wypisuje zestawienie temperatur w skali
 Fahrenheita i Celsjusza wg wzoru: C = (5/9)*(F – 32).
*/
int main(void)
{
    int dolna = 0,
        gorna = 300,
        krok = 20,
        fahr, celsius;
    fahr = dolna;
    while (fahr<=gorna)
    {
        celsius = 5*(fahr - 32)/9;
        printf("%3d%6d\n",fahr,celsius);
        fahr = fahr + krok;
    } //while
}
/* Zapis "%3d%6d\n" formatuje zapis tekstu.
%3d wyświetla liczbe całkowitą z minimalną szerokością
do minimum 3 znaków. Jeśli liczba ma mniej niż 3 cyfry
zostanie dopełniona spacjami z lewej strony.
%6d do minimum 6 znaków */
