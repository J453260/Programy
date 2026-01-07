#include <stdio.h>
#include <stdlib.h>

void Fibb(int Fib [], int m)
{
    Fib[0]=0;
    Fib[1]=1;
    for(int i=2; i<=m; i++)
    {
        Fib[i]=Fib[i-1]+Fib[i-2];
    }
}

int main()
{
    int rozmiar;

    // Pobranie rozmiaru tablicy od użytkownika
    printf("Podaj rozmiar tablicy do obliczen: ");
    scanf("%d", &rozmiar);
    int min, max;
    //wprowadzenie ideksów dla max
    do
    {
        //sprawdzenie poprawnosci indeksow
        printf("Podaj dolny zakres : ");
        scanf("%d", &min);
        if (min < 0 || min > rozmiar)
        {
            printf("Dolny zakres musi byc w zakresie od 0 do %d.\n", rozmiar - 1);
        }
    }
    while (min < 0 || min > rozmiar);

    // Wprowadzenie zakresu indeksów dla max
    do
    {
        printf("Podaj gorny zakres: ");
        scanf("%d", &max);
        if (max < min || max > rozmiar)
        {
            printf("imax musi byc w zakresie od min (%d) do %d.\n", min, rozmiar - 1);
        }
    }
    while (max < min || max > rozmiar);

    int i;
    int Fib[max+1];

    Fibb(Fib, max);

    for(int i=min; i<=max; i++)
    {
        printf("%d wyraz ciagu Fibonacciego: %d\n", i, Fib[i]);
    }
    return 0;
}
