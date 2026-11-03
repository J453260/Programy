#include <stdio.h>
#include <stdlib.h>
const int dolna = 0,
          gorna = 300,
          krok = 20;
float fahr, celsius;
int main()
{;
    float celsius; // temperatura Celsiusza
    for (celsius = dolna; celsius <= gorna; celsius += krok)
        printf("%3.0f\t%6.1f\n",celsius ,((9.0/5.0)*celsius)+32);
}
