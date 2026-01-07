#include <stdio.h>
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
int main()
{
    unsigned n;
    printf("Obliczanie n! metoda iteracyjna\n");
    printf("Podaj liczbe naturalna n: ");
    scanf("%u",&n);
    printf("%u! = %u\n",n,silnia_i1(n));
}
