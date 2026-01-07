#include <stdio.h>
#include <math.h>
#include <stdlib.h> //dla exit(0)
/*
 Obliczanie pierwiastkow rownania kwadratowego:
 a*x^2 + b*x + c = 0.
 ---------------------------------------------------
 Autor: Jan Bajor Krakow, 29.10.2024
 ---------------------------------------------------
*/
int main(void)
{
    char d;
    do
    {
        double a,b,c; // wspolczynniki rown. kwadr.
        double Delta,x0,x1,x2; // wyroznik i pierwiastki
        printf("Pierwiastki rownania kwadratowego: ");
        printf("a*x^2 + b*x + c = 0.\n");
        printf("Podaj wspolczynniki a, b, c: ");
        scanf("%lf%lf%lf",&a,&b,&c);
        Delta = b*b - 4*a*c;
        if (Delta > 0.0)   // dwa pierwiastki
        {
            x1 = -(b + sqrt(Delta))/2/a;
            x2 = -(b - sqrt(Delta))/2/a;
            printf("Dwa pierwiastki: x1 = %lf, x2 = %lf\n",x1,x2);
        }
        else if (Delta == 0.0)     // jeden pierwiastek
        {
            x0 = -b/2/a;
            printf("Jeden pierwiastek podwojny: x0 = %lf\n",x0);
        }
        else   // brak pierwiastkow
        {
            printf("Brak pierwiastkow: Delta = %lf\n",Delta);
        }

        printf("Czy chcesz kontynuowac? [t/n]: ");
        scanf(" %c",&d);

        if(d=='N' || d=='n')
        {
            printf("Koniec programu.\n");
            exit(0);
        }
    }
    while(d == 't' || d == 'T');
}
