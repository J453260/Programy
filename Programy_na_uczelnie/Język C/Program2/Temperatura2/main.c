#include <stdio.h>
#include <stdlib.h>
int main()
{
    float dolna = 0,
          gorna  = 300,
          krok = 20,
          fahr;
    for(fahr = dolna; fahr<=gorna; fahr += krok)
    {
        printf("%3.0f\t%6.1f\n",fahr,5.0/9*(fahr - 32));
    }
    return 0;
}
