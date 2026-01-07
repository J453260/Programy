#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "TypZespolone.h"

zesp CzytajZ(FILE *wp)
{
    char c;
    zesp z;
    int wynik = fscanf(wp,"%c%lg%c%lg%c%c",&c,&z.Re,&c,&z.Im,&c,&c);
    assert(wynik!=2 && "Nie udalo sie zczytac dwoch liczb z pliku.");
    return z;
}

int PiszZ(FILE *wp, zesp z)
{
    if(fprintf(wp, "%lg %lg", z.Re, z.Im)>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

zesp SprzezenieZ(zesp z)
{
    z.Im = -z.Im;
    return z;
}

double ModulZ(zesp z)
{
    return sqrt(pow(z.Re, 2) + pow(z.Im, 2));
}

double FazaZ(zesp z)
{
    double modul = sqrt(pow(z.Re, 2) + pow(z.Im, 2)); //obliczanie modulu liczby zespolonej
    assert(modul != 0 && "Nie mozna obliczyc fazy dla z = 0!"); //sprawdzenie czy modul jest rozny od zera
    double faza = z.Re/modul; //wyliczanie fazy
    double fi = acos(faza); //obliczanie arccos
    if(z.Im>=0)
    {
        return fi;
    }
    else
    {
        return 2*M_PI - fi;
    }
}

zesp SumaZ(zesp z1, zesp z2)
{
    zesp z3;
    z3.Re = z1.Re + z2.Re;
    z3.Im = z1.Im + z2.Im;
    return z3;
}

zesp RoznicaZ(zesp z1, zesp z2)
{
    zesp z3;
    z3.Re = z1.Re - z2.Re;
    z3.Im = z1.Im - z2.Im;
    return z3;
}

zesp IloczynZ(zesp z1, zesp z2)
{
    zesp z3;
    z3.Re = (z1.Re * z2.Re) - (z1.Im * z2.Im);
    z3.Im = (z1.Re * z2.Im) + (z1.Im * z2.Re);
    return z3;
}

zesp IlorazZ(zesp z1, zesp z2)
{
    zesp z3;
    double a = z1.Re;  // Część rzeczywista z1
    double b = z1.Im;  // Część urojona z1
    double c = z2.Re;  // Część rzeczywista z2
    double d = z2.Im;  // Część urojona z2
    assert(c!=0 && d!=0 && "Nie mozna dzielic przez zero.");
    z3.Re = (a*c + b*d)/(c*c + d*d);
    z3.Im = (b*c - a*d)/(c*c + d*d);
    return z3;
}
