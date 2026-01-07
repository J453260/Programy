#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int R(long long int Fib2 [], int i)
{
    if(i==0)
    {
        return 0;
    }
    else if(i==1)
    {
        return 1;
    }
    else
    {
        return Fib2[i] = R(Fib2, i - 1) + R(Fib2, i - 2);
    }
}

long long int It(long long int Fib1 [], int n)
{
    Fib1[0]=0;
    Fib1[1]=1;
    for (int i = 2; i <= n; i++)
    {
        Fib1[i]=Fib1[i-1]+Fib1[i-2];
    }
    return Fib1[n];
}

int main()
{
    long long int n;
    printf("Ktory wyraz ciagu Fibonacciego chcesz wyznaczyc: ");
    scanf("%lld", &n);
    long long int Fib1[n];
    long long int Fib2[n];

     // Mierzenie czasu dla metody rekurencyjnej
    clock_t start_R = clock();
    long long int result_R = R(Fib2, n);
    clock_t end_R = clock();
    double time_R = (double)(end_R - start_R) / CLOCKS_PER_SEC;

    // Mierzenie czasu dla metody iteracyjnej
    clock_t start_It = clock();
    long long int result_It = It(Fib1, n);
    clock_t end_It = clock();
    double time_It = (double)(end_It - start_It) / CLOCKS_PER_SEC;

    printf("Wynik dla metody iteracyjnej: %lld\n", result_It);
    printf("Czas: %.6f s\n", time_It);
    printf("Wynik dla metody rekurencyjnej: %lld\n", result_R);
    printf("Czas: %.6f s\n", time_R);
    return 0;

}

//funkcja rekurencyjna trwa dłużej
