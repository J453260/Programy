#include <stdio.h>
#include <stdlib.h>

#define DOLNA 0
#define GORNA 300
#define KROK 20

int main()
{
    float fahr; // temperatura Fahrenheita
    for (fahr = DOLNA; fahr <= GORNA; fahr += KROK)
        printf("%3.0f%6.1f\n",fahr,5.0/9*(fahr - 32));
}
