#ifndef Funkcje_h
#define Funkcje_h

int WypiszTekst(FILE *wp, const char *tekst);
int CzytajTekst(FILE *wp, char *tekst, int max1);
int KopiujTekst(const char *skad, char *dokad, int max1);
int WszystkieZnaki(const char *tekst);
int CzarneZnaki(const char *tekst);
int Linie(const char *tekst);
int Slowa(const char *tekst);

#endif Funkcje_h
