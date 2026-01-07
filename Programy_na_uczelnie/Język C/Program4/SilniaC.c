#include <stdio.h>
/*===================================================
 Obliczanie n!
 ---------------------------------------------------
 Autor: Wieslaw Placzek Krakow, 04.03.2024
 ===================================================*/
// Obliczanie n! metoda rekurencyjna
unsigned silnia_r1(unsigned n)
{
    if (n > 1)
        return n*silnia_r1(n-1);
    else
        return 1;
}
int main()
{
    unsigned n;
    printf("Obliczanie n! metoda rekurencyjna\n");
    printf("Podaj liczbe naturalna n: ");
    scanf("%u",&n);
    printf("%u! = %u\n",n,silnia_r1(n));
}
