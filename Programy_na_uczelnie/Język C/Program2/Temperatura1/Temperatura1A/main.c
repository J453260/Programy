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
        celsius = 5/9*(fahr - 32);
        printf("%d\t%d\n",fahr,celsius);
        fahr = fahr + krok;
    } //while
}
/* Z wyrażenia celsius = 5/9*(fahr - 32); otrzymamy wynik 0, ponieważ liczby 5 i 9 są
domyślnie ustawnione jako int czyli liczby całkowite, więc wynik dzielenia będzie również całkowity.
Program automatycznie zaokrągla w dół. */
