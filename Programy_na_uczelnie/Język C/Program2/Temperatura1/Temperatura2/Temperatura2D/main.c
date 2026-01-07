#include <stdio.h>
#include <stdlib.h>
const int dolna = 0,
          gorna = 300,
          krok = 20;
float fahr, celsius;
int main()
{
    printf("Program zamienia temperature ze skali Celsiusza na skale Fahrenheita\n");
    printf("Napisal: Jan Bajor dnia 26.10.2024 o godzinie 22:13 w domu\n");
    for (fahr = dolna; fahr <= gorna; fahr += krok)
        printf("%3.0f C\t%6.1f F\n",fahr, 5.0/9.0*(fahr - 32.0));
}
