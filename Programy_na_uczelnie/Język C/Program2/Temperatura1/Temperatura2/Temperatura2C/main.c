#include <stdio.h>
#include <stdlib.h>
const int dolna = 0,
          gorna = 300,
          krok = 20;
float fahr, celsius;
int main()
{
    dolna = 20;
    float fahr; // temperatura Fahrenheita
    for (fahr = dolna; fahr <= gorna; fahr += krok)
        printf("%3.0f%6.1f\n",fahr,5.0/9*(fahr - 32));
}
/* Program nie działa */
