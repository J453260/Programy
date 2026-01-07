#include <stdio.h>
#include <stdlib.h>

/*
 Rozwiazywanie rownania kwadratowego: a*x^2 + b*x + c = 0.
 Autor: Jan Bajor Krakow, 30.10.2024
*/
void rKwad(double a, double b, double c)
{
    double Delta,x0,x1,x2; // wyroznik i pierwiastki
    Delta = b*b - 4*a*c;
    if (Delta > 0.0)   // dwa pierwiastki
    {
        x1 = -(b + sqrt(Delta))/2/a;
        x2 = -(b - sqrt(Delta))/2/a;
        printf("Dwa pierwiastki: x1 = %g, x2 = %g\n",x1,x2);
    }
    else if (Delta == 0.0)     // jeden pierwiastek
    {
        x0 = -b/2/a;
        printf("Jeden pierwiastek podwojny: x0 = %g\n",x0);
    }
    else   // brak pierwiastkow
        printf("Brak pierwiaskow: Delta = %g\n",Delta);
}

int main()
{
    double a, b, c;
    printf("Podaj wspolczynniki a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    rKwad(a, b, c);
}
