#include <stdio.h>
#include <stdlib.h>
#include "OperacjeMacierzowe.h"
#include <assert.h>
#include <omp.h>
int CzytajMacierz(FILE *wp, char *nazwa, int n, double M[n][n])
{
    assert(wp != NULL);
    int sukces = 1;
    if (fscanf(wp, "%s", nazwa) != 1)
    {
        fprintf(stderr, "Blad: Nie udalo sie odczytac nazwy macierzy.\n");
        return 0;
    }
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fscanf(wp, "%lf", &M[i][j]) != 1)    // %lf dla double
            {
                fprintf(stderr, "Blad: Nie udalo sie odczytac elementu macierzy.\n");
                sukces = 0; // Porażka
            }
        }
    }
    if(!sukces)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int WypiszMacierz(FILE *wp, char *nazwa, int n, double M[n][n])
{
    int sukces = 1;
    assert(wp != NULL);
    fprintf(wp, "%s\n", nazwa);
    #pragma omp parallel for collapse(2)
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(fprintf(wp, "%lf", M[i][j])<0)
            {
                sukces = 0;
            }
        }
    }

    if(!sukces)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int CzytajWektor(FILE *wp, char *nazwa, int n, double V[n])
{
    int sukces = 1;
    assert(wp != NULL);
    if(fscanf(wp, "%s", nazwa) != 1)
    {
        fprintf(stderr, "Nie udalo sie odczytac nazwy wektora.\n");
        sukces = 0;
    }
    for(int i=0; i<n; i++)
    {
        if (fscanf(wp, "%lf", &V[i]) != 1)    // %lf dla double
        {
            fprintf(stderr, "Blad: Nie udalo sie odczytac elementu wektora.\n");
            sukces = 0; // Porażka
        }
    }

    if(!sukces)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int WypiszWektor(FILE *wp, char *nazwa, int n, double V[n])
{
    assert(wp != NULL);
    fprintf(wp, "%s\n", nazwa);
    for(int i=0; i<n; i++)
    {
        if(fprintf(wp, "%lf", V[i]))
        {
            return 0;
        }
    }
    fprintf(wp, "\n");
    return 1;
}

int CzytajLiczbe(FILE *wp, char *nazwa, double *c)
{
    assert(wp != NULL);
    if(fscanf(wp, "%s", nazwa) != 1)
    {
        fprintf(stderr, "Nie udalo sie odczytac nazwy liczby.\n");
        return 0;
    }

    if (fscanf(wp, "%lf", c) != 1)
    {
        fprintf(stderr, "Blad: Nie udalo sie odczytac wartosci liczby.\n");
        return 0;
    }
    return 1;
}

int WypiszLiczbe(FILE *wp, char *nazwa, double c)
{
    assert(wp != NULL);
    if(fprintf(wp, "%s\n", nazwa)<0)
    {
        return 0;
    }

    if(fprintf(wp, "%lf", c)<0)
    {
        return 0;
    }
    return 1;
}

void TransponujMacierz(int n, double M[n][n], double MT[n][n])
{
    assert(M != NULL && MT != NULL);
    #pragma omp parallel for collapse(2)
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            MT[j][i]=M[i][j];
        }
    }
}

void DodajMacierze(int n, double A[n][n], double B[n][n], double C[n][n])
{
    assert(A != NULL && B != NULL && C != NULL);
    #pragma omp parallel for collapse(2)
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}

void OdejmijMacierze(int n, double A[n][n], double B[n][n], double C[n][n])
{
    assert(A != NULL && B != NULL && C != NULL);
    #pragma omp parallel for collapse(2)
   for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            C[i][j]=A[i][j]-B[i][j];
        }
    }
}

void MnozLiczbaMacierz(int n, double c, double A[n][n], double B[n][n])
{
    assert(A != NULL && B != NULL);
    #pragma omp parallel for collapse(2)
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            B[i][j]=c*A[i][j];
        }
    }
}

void MnozMacierzWektor(int n, double A[n][n], double V[n], double W[n])
{
    assert(A != NULL && V != NULL && W != NULL);
    #pragma omp parallel for collapse(2)
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            W[i]=0;
            W[i]+=A[i][j]*V[j];
        }
    }
}

void MnozMacierze(int n, double A[n][n], double B[n][n], double C[n][n])
{
    assert(A != NULL && B != NULL && C != NULL);
    #pragma omp parallel for collapse(2)
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            C[i][j]+=A[i][j]*B[i][j];
        }
    }
}
