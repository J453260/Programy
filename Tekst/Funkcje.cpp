#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int WypiszTekst(const string& tekst)
{
    return tekst.length();
}

int CzarneZnaki(const string& tekst)
{
    int licznik=0;
    for(char c : tekst)
    {
        if(c != ' ' && c != '\t' && c != '\n')
        {
            licznik++;
        }
    }
    return licznik;
}

int Linie(const string& tekst)
{
    int Licznik=0;
    for(char c : tekst)
    {
        if(c == '\n')
        {
            Licznik++;
        }
    }

    if(!tekst.empty() && tekst.back() != '\n')
    {
        Licznik+=1;
    }
    return Licznik;
}

int Slowa(const string& tekst)
{
    int licznik=0;
    bool Wsl = false;
    for(char c : tekst)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            Wsl=false;
        }
        else
        {
            // Jeśli napotkamy znak, który nie jest spacją, sprawdzamy, czy to początek nowego słowa
            if (!Wsl)
            {
                licznik++; // Nowe słowo
                Wsl = true;  // Ustawiamy flagę, że jesteśmy w słowie
            }
        }
    }

    return licznik;
}

string Panel()
{
    string nazwaPliku;
    cout << "Podaj nazwe pliku .txt do odczytu: ";
    cin >> nazwaPliku;

    ifstream plik(nazwaPliku);
    if (!plik)
    {
        cerr << "Blad: nie mozna otworzyc pliku!" << endl;
        return 1;
    }

    string tekst;
    string linia;

    // ↓ Wczytanie całej zawartości pliku
    while (getline(plik, linia))
    {
        tekst += linia + "\n";
    }

    plik.close();

    return tekst;
}
