#include <stdio.h>
#include <limits.h>
#include <float.h>
/*===================================================
 Obliczanie n!
 ---------------------------------------------------
 Autor: Wieslaw Placzek Krakow, 04.03.2024
 ===================================================*/
// Obliczanie n! metoda iteracyjna: typ unsigned
unsigned silnia_i1(unsigned n)
{
    unsigned i,iloczyn;
    for (i = iloczyn = 1; i <= n; ++i)
        iloczyn *= i;
    return iloczyn;
}

unsigned long silnia_i2(unsigned long m)
{
    unsigned long i,iloczyn;
    for (i = iloczyn = 1; i <= m; ++i)
        iloczyn *= i;
    return iloczyn;
}

double silnia_i3(double o)
{
    double i,iloczyn;
    for (i = iloczyn = 1; i <= o; ++i)
        iloczyn *= i;
    return iloczyn;
}

int main()
{
    unsigned n, n_max = ULONG_MAX;
    unsigned long m, m_max = ULONG_MAX;
    double o, o_max = DBL_MAX;
    printf("Obliczanie n! metoda iteracyjna\n");
    printf("n - unsigned\n");
    printf("Podaj liczbe naturalna n: ");
    scanf("%u",&n);
    m=n;
    o=n;
    printf("m=n\no=n\n");
    printf("n - unsigned\n");
    printf("m - unsigned long\n");
    printf("o - double\n");
    printf("n: %u! = %u\n",n,silnia_i1(n));
    printf("m: %lu! = %lu\n",m,silnia_i2(m));
    printf("o: %g! = %g\n",o,silnia_i3(o));
    printf("Unsigned_max: %u\n",n_max);
    printf("Unsigned_long_max: %u\n",m_max);
    printf("Double_max: %u\n",o_max);
}
