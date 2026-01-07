#include <stdio.h>
/*=======================================================
 Program zlicza w tekscie: cyfry (kazda oddzielnie),
 biale znaki oraz pozostale znaki.
 -------------------------------------------------------
 Autor: Jan Bajor Krakow, 26.11.2024
 =======================================================*/
#define NC 10 // rozmiar tablicy cyfr
int main()
{
    int c, // kod ASCII znaku
        i, // licznik petli for
        biale = 0, // licznik bialych znakow
        inne = 0, // licznik innych znakow
        cyfry[NC] = {0}; // liczniki cyfr
    printf("Zliczanie cyfr, bialych znakow i pozostalych "
           "znakow w tekscie:\n");
    while ( (c = getchar()) != EOF ) // wczytanie znaku
        switch (c)  // rozpoznanie znaku
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            cyfry[c - '0']++; // zliczanie cyfr
            break;
        case ' ':
        case '\n':
        case '\t':
            biale++; // zliczanie bialych znakow
            break;
        default:
            inne++; // zliczanie innych znakow
            break;
        } // switch
    printf("Cyfry:\n");
    for (i = 0; i < NC; ++i)
        printf("\t%c: %d\n",'0'+i,cyfry[i]);
    printf("Biale znaki: %d\nInne znaki: %d\n",biale,inne);
}
