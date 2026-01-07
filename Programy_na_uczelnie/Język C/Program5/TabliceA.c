#include <stdio.h>
#include <stdlib.h>

long long int wypelnij(long long int F[],long long int n)
{
    int i;
    F[0]=0;
    F[1]=1;
    for (i = 2; i <= n; i++)
    {
        F[i]=F[i-1]+F[i-2];
    }
    return F[n];
}

int main()
{
    long long int n;
    printf("Ktory wyraz ciagu Fibbonaciego chcesz wyznaczyc: ");
    scanf("%lld", &n);
    long long int Fib[n];
    wypelnij(Fib, n);
    printf("Wynik: %lld", Fib[n]);
}
