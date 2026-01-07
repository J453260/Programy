#include <stdio.h>
/*===================================================
 Obliczanie n!
 ---------------------------------------------------
 Autor: Wieslaw Placzek Krakow, 04.03.2024
 ===================================================*/
// Obliczanie n! metoda rekurencyjna

double silnia_r1(double n)
{
 if (n > 1)
 return n*silnia_r1(n-1);
 else
 return 1;
}

double silnia_r2(double m)
{
    return (m > 1)?(m*silnia_r1(m-1)):1;
}
int main()
{
    double n, m;
    printf("Obliczanie n! metoda rekurencyjna\n");
    printf("Podaj liczbe naturalna n: ");
    scanf("%le",&n);
    m=n;
    printf("if-else %g! = %g\n",n,silnia_r1(n));
    printf("Operator warunkowy ?: %g! = %g\n",m,silnia_r1(m));
}
//wyniki są takie same
