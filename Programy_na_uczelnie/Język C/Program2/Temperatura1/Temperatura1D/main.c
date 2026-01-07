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
        krok = 20;
    int fahr, celsius;
    fahr = dolna;
    while (fahr<=gorna)
    {
        celsius = 5.0/9*(fahr - 32);
        printf("%3d%6d\n",fahr,celsius);
        fahr = fahr + krok;
    } //while
}
/* Typ int będzie wyświetlał wartości całkowite.
Natomiast float wartości z częścią ułamkową
Zapisy: "fahr = fahr + krok" i "fahr+=krok" są sobie
równoważne i wykonują tą samą operacje.*/
