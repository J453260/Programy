#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>
#include <time.h>
#include "OperacjeMacierzowe.h"

int main()
{
    omp_set_num_threads(8);
    FILE *wp;
    wp = fopen("Macierze.txt", "r");
    assert(wp != NULL);
    char NazwaMacierzy[100];
    int n;
    printf("Podaj rozmiar macierzy (n): ");
    scanf("%d", &n);
    assert(n>0);

    clock_t s1, s2, k1, k2;
    double czas;

    s1 = clock();

    double Macierz[n][n];
    if(CzytajMacierz(wp, NazwaMacierzy, n, Macierz))
    {
        printf("Nazwa macierzy: %s\n", NazwaMacierzy);
        printf("Macierz %dx%d:\n", n, n);
        #pragma omp parallel for collapse(2)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%.2lf ", Macierz[i][j]);
            }
        }
    }
    else
    {
        printf("Nie udalo sie wczytac macierzy.\n");
    }
    fclose(wp);
    FILE *wp2;
    wp2 = fopen("Pisanie.txt", "w");
    assert(wp2 != NULL);

    printf("\n");
    if(WypiszMacierz(wp2, NazwaMacierzy, n, Macierz))
    {
        printf("Udalo sie przepisac nazwe i zawartosc macierzy do pliku.\n");
    }
    else
    {
        printf("Nie udalo sie przepisac nazwy i zawartosci macierzy do pliku.\n");
    }

    FILE *wek;
    wek = fopen("Wektor.txt", "r");
    assert(wek != NULL);

    char NazwaWektora[100];
    double V[n];
    if(CzytajWektor(wek, NazwaWektora, n, V))
    {
        printf("Udalo sie przeczytac nazwe i zawartosc wektora V.\n");
        printf("Nazwa wektora: %s\n", NazwaWektora);
    }
    fclose(wek);

    if(WypiszWektor(wp2, NazwaWektora, n, V))
    {
        printf("Udalo sie przepisac nazwe i zawartosc wektora do pliku.\n");
    }

    FILE *liczba;
    liczba = fopen("Liczba.txt", "r");
    assert(liczba != NULL);

    char NazwaLiczby[100];
    double c;
    if(CzytajLiczbe(liczba, NazwaLiczby, &c))
    {
        printf("Udalo sie wczytac nazwe i wartosc liczby.\n");
        printf("Nazwa liczby: %s\n", NazwaLiczby);
        printf("Wartosc liczby: %.2f\n", c);
    }

    if(WypiszLiczbe(wp2, NazwaLiczby, c))
    {
        printf("Udalo sie przepisac nazwe i wartosc liczby do pliku.\n");
    }

    double MacierzTransponowana[n][n];
    TransponujMacierz(n, Macierz, MacierzTransponowana);
    double A[n][n];
    double B[n][n];
    double C[n][n];
    char NazwaA[100];
    char NazwaB[100];

    FILE *MA;
    MA = fopen("A.txt", "r");
    assert(MA != NULL);

    FILE *MB;
    MB = fopen("B.txt", "r");
    assert(MB != NULL);

    CzytajMacierz(MA, NazwaA, n, A);
    CzytajMacierz(MB, NazwaB, n, B);
    DodajMacierze(n,A,B,C);
    OdejmijMacierze(n,A,B,C);

    double d;
    double D[n][n];

    k1=clock();

    printf("\nPodaj liczbe przez ktora beda mnozone macierze: ");
    scanf("%lf", &d);

    s2 = clock();

    printf("\n");
    assert(d != 0);
    MnozLiczbaMacierz(n, d, A, D);
    printf("Wartosci macierzy pomnozone przez liczbe: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%.2f", D[i][j]);
            printf("\n");
        }
    }
    double W[n];
    printf("\nWartosci macierzy pomnozone przez wektor:\n");
    MnozMacierzWektor(n, A, V, W);
    for(int i=0; i<n; i++)
    {
        printf("%.2f", W[i]);
        printf("\n");
    }

    printf("\nWartosci maciezy pomnozonych przez siebie:\n");
    MnozMacierze(n, A, B, C);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%.2f", C[i][j]);
            printf("\n");
        }
    }

    k2 = clock();
    czas = ((double)((k2-s2)+(k1-s1)))/CLOCKS_PER_SEC;
    printf("\n\n");
    printf("Czas wykonania programu: %lf s", czas);
    return 0;
}
