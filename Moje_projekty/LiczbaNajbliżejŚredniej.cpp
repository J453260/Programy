#include <iostream>
#include <cmath> //dla fabs
#include <vector>
#include <cassert>
using namespace std;

float LiczbaNajblizejSredniej(vector<float> liczby)
{
    float m,s,z,liczba,rozmiar;
    s=0.0;
    rozmiar = liczby.size();
    for(float i : liczby)
    {
        s+=i;
    }
	m=s/rozmiar;
	vector<float> roznice;

	for(float i : liczby)
    {
        roznice.push_back(fabs(i-m));
    }

	z = roznice.front();
	liczba = liczby.front();
	int index = 0;

	for(int i=0; i<roznice.size(); i++)
    {
        if(z>roznice[i])
        {
            z=roznice[i];
            index = i;
        }
    }

    liczba = liczby[index];

	return liczba;
}

int main()
{
    vector<float> liczby;
    string wejscie;
    cout<<"Podaj liczby oddzielonych spacja lub EXIT by zakonczyc: ";

    while(true)
    {
        cin>>wejscie;
        if(wejscie == "EXIT")
        {
            break;
        }
        liczby.push_back(stoi(wejscie));
    }

	cout<<"Liczba najblizej sredniej to: "<<LiczbaNajblizejSredniej(liczby);

	return 0;
}


/*

	Algorytm:
	Nowy wektor na wartość bezwzględną z różnicy liczby i średniej.
	Nowa zmienna na pierwszą liczbę.
	Znajdź najmniejszą różnicę i przypisz do zmiennej "liczba" liczbę
	dla najmniejszej średniej.

*/
