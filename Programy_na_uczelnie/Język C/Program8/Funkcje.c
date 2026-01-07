#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funkcje.h"

int WypiszTekst(FILE *wp, const char *tekst)
{
    int Znaki = strlen(tekst);
    fputs(tekst, wp);
    fprintf(wp, "\n%d", Znaki);
    return Znaki;
}

int CzytajTekst(FILE *wp, char *t, int max1)
{
    char c;
    int licznik=0;
    while (((c = fgetc(wp)) != EOF) && (licznik < max1))
    {
        t[licznik++] = c;
    }
    t[licznik] = '\0';
    return licznik;
}

int KopiujTekst(const char *skad, char *dokad, int max1)
{
    int licznik=0;
    while (*skad && licznik < max1)
    {
        *dokad++ = *skad++;
        licznik++;
    }
    *dokad = '\0';

    return licznik;
}

int WszystkieZnaki(const char *tekst)
{
    return strlen(tekst);
}

int CzarneZnaki(const char *tekst)
{
    int licznik=0;
    while(*tekst)
    {
        if(*tekst != ' ' && *tekst != '\t' && *tekst != '\n')
        {
            licznik++;
        }
        tekst++;
    }
    return licznik;
}

int Linie(const char *tekst)
{
    int Licznik = 0;
    while (*tekst)
    {
        if (*tekst == '\n')
        {
            Licznik++;
        }
        tekst++;
    }

    // Dodaj linię, jeśli ostatni znak nie jest '\n'
    if (*(tekst - 1) != '\n')
    {
        Licznik++;
    }
    return Licznik;
}

int Slowa(const char *tekst)
{
    int licznik = 0, w_slowie = 0;
    while (*tekst)
    {
        if (*tekst == ' ' || *tekst == '\n' || *tekst == '\t')
        {
            w_slowie = 0;
        }
        else if (!w_slowie)
        {
            w_slowie = 1;
            licznik++;
        }
        tekst++;
    }
    return licznik;
}
