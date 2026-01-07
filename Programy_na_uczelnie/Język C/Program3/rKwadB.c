#include <stdio.h>
#include <math.h>
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

        if (a!=0 && b!=0 && c!=0)
        {
            printf("Twoje rownaie: %gx^2",a);
            char znak_b = (b>0) ? '+' : '-';
            char znak_c = (c>0) ? '+' : '-';
            printf(" %c %gx %c %g\n", znak_b, fabs(b), znak_c, fabs(c));
        }
        else
        {
            if(b==0 && c==0)
            {
                printf("Twoje rownanie: %gx^2 \n", a);
            }
            else if(b!=0 && c==0)
            {
                printf("Twoje rownanie: %gx^2 ", a);
                b<0 ? printf("%gx\n",b) : printf("+ %gx \n",b);
            }
            else if(b==0 && c!=0)
            {
                printf("Twoje rownanie: %gx^2 ", a);
                c<0 ? printf("%g\n",c) : printf("+ %g \n",c);
            }
        }

        if (a!=0)
        {
            Delta = b*b - 4*a*c;
            if (Delta > 0.0)   // dwa pierwiastki
            {
                x1 = -(b + sqrt(Delta))/2/a;
                x2 = -(b - sqrt(Delta))/2/a;
                if(x1 == 0)
                    printf("Dwa pierwiastki: x1 = 0, x2 = %g\n",x2);
                else if(x2 == 0)
                    printf("Dwa pierwiastki: x1 = %g, x2 = 0\n",x1);
                else
                    printf("Dwa pierwiastki: x1 = %g, x2 = %g\n",x1,x2);
            }
            else if (Delta == 0.0)     // jeden pierwiastek
            {
                x0 = -b/2/a;
                if (x0 == 0)
                    printf("Jeden pierwiastek podwojny: x0 = 0\n");
                else
                    printf("Jeden pierwiastek podwojny: x0 = %g\n",x0);
            }
            else   // brak pierwiastkow
            {
                printf("Brak pierwiastkow: Delta = %g\n",Delta);
            }
        }
        else
        {
            printf("W rownaniu kwadratowym wspolczynnik a nie moze byc rowny 0\n");
        }

        printf("Czy chcesz kontynuowac? [t/n]: ");
        scanf(" %c", &d);
    }
    while(d == 't');
}
