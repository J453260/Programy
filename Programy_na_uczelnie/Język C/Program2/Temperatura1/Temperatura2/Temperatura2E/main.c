#include <stdio.h>
#include <stdlib.h>
const int dolna = 0,
          gorna = 300,
          krok = 20;
float fahr, celsius;
int main()
{
    for (fahr = gorna; fahr >= dolna; fahr -= krok)
        printf("%3.0f C\t%6.1f F\n",fahr ,5.0/9*(fahr - 32.0));
}
