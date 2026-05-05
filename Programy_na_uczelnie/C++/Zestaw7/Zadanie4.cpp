#include <iostream>
using namespace std;

/*

Wzór:

Suma od 0 do nieskończoności:
(-1)^n * (x^(2n + 1) / (2n+1)!)

*/


long long Silnia(int n)
{
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

long double Pow(long double x, int n)
{
    long double res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= x;
    }
    return res;
}


long double Rozwiniecie(int x)
{
    long double wynik = 0;
    for(int i=0; i<=20; i++)
    {
        long double znak = (i % 2 == 0) ? 1 : -1;
        wynik += znak*(Pow(x, 2*i + 1) / Silnia(2*i + 1));
    }

    return wynik;
}



int main()
{
    int N = 10;
    for(int i = 0; i<=N; i++)
    {
        cout<<Rozwiniecie(i)<<endl;
    }

    return 0;
}
