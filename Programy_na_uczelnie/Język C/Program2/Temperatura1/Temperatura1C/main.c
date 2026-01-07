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
    float fahr, celsius;
    fahr = dolna;
    while (fahr<=gorna)
    {
        celsius = 5.0/9.0*(fahr - 32.0);
        printf("%3.0f%6.1f\n",fahr,celsius);
        fahr = fahr + krok;
    } //while
}
/* Program wyświetla liczby z częścią ułamkową z dokładnością do 1
cyfry po przecinku. */
