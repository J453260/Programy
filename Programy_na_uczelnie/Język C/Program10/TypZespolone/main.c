#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "TypZespolone.h"

int main(int argc, char *argv[])
{
    assert(argc == 3 && "Niepoprawna ilosc argumentow.\n");
    FILE *wp = fopen(argv[1], "r");
    assert(wp != NULL);
    zesp z1 = CzytajZ(wp);
    printf("Pierwsza liczba zespolona z pliku: %lg", z1.Re);
    (z1.Im>0)?(printf(" + %lgi\n", z1.Im)):(printf("%lgi\n"), z1.Im);
    zesp z2 = CzytajZ(wp);
    fclose(wp);

    FILE *wp2 = fopen(argv[2], "w");
    assert(wp2 != NULL);

    int wynik = PiszZ(wp2, z1);
    assert(wynik && "Nie udalo sie przepisac liczby zespolonej do pliku.");
    printf("Udalo sie przepisac liczbe zespolona do pliku.\n");
    fclose(wp2);

    printf("Liczba sprzezona: ");
    if (SprzezenieZ(z1).Im >= 0)
    {
        printf("%.2f + %.2fi\n", SprzezenieZ(z1).Re, SprzezenieZ(z1).Im);
    }
    else
    {
        printf("%.2f - %.2fi\n", SprzezenieZ(z1).Re, -SprzezenieZ(z1).Im);
    }
    printf("Modul liczby zespolonej: %lg\n", ModulZ(z1));
    printf("Faza liczby zespolonej: %lg\n\n", FazaZ(z1));

    printf("Druga liczba zespolona z pliku: %lg", z2.Re);
    (z2.Im>0)?(printf(" + %lgi\n", z2.Im)):(printf(" - %lgi\n"), -z2.Im);

    printf("\n");
    if(z1.Re==0 && z1.Im==0 && z2.Re==0 && z2.Im==0)
    {
        printf("Wprowadzone liczby sa zerami.");
        return 0;
    }
    else
    {
        printf("Suma liczb zespolonych: %lg", SumaZ(z1, z2).Re);
        (SumaZ(z1, z2).Im>=0)?(printf(" + %lgi\n", SumaZ(z1, z2).Im)):(printf(" - %lgi\n", -SumaZ(z1, z2).Im));

        printf("Roznica liczb zespolonych: %lg", RoznicaZ(z1, z2).Re);
        (RoznicaZ(z1, z2).Im>=0)?(printf(" + %lgi\n", RoznicaZ(z1, z2).Im)):(printf(" - %lgi\n", -RoznicaZ(z1, z2).Im));

        printf("Iloczyn liczb zespolonych: %lg", IloczynZ(z1, z2).Re);
        (IloczynZ(z1, z2).Im>=0)?(printf(" + %lgi\n", IloczynZ(z1, z2).Im)):(printf(" - %lgi\n", -IloczynZ(z1, z2).Im));

        printf("Iloraz liczb zespolonych: %lg", IlorazZ(z1, z2).Re);
        (IlorazZ(z1, z2).Im>=0)?(printf(" + %lgi\n", IlorazZ(z1, z2).Im)):(printf(" - %lgi\n", -IlorazZ(z1, z2).Im));
    }
    return 0;
}
