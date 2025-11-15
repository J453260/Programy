#include <iostream>
#include <fstream>
#include "Funkcje.h"
using namespace std;

int main()
{
    string tekst;
    tekst = Panel();
    cout << "===== Analiza tekstu =====\n";
    cout << "Liczba znakow: " << WypiszTekst(tekst) << endl;
    cout << "Czarne znaki: " << CzarneZnaki(tekst) << endl;
    cout << "Liczba linii: " << Linie(tekst) << endl;
    cout << "Liczba slow:  " << Slowa(tekst) << endl;
    return 0;
}
