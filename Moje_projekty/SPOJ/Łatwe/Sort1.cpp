#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Punkt
{
    double x, y;
    string nazwa;
    double odleglosc;
};

double Odleglosc(double a, double b)
{
    double odleglosc = (double)(a*a + b*b);
    return sqrt(odleglosc);
}

void quicksort(Punkt *tablica, int lewy, int prawy)
{
    Punkt v = tablica[(lewy + prawy) / 2];
    int i, j;
    Punkt x;
    i = lewy;
    j = prawy;
    do
    {
        while (tablica[i].odleglosc < v.odleglosc) i++;
        while (tablica[j].odleglosc > v.odleglosc) j--;
        if (i <= j)
        {
            x = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = x;
            i++;
            j--;
        }
    }
    while (i <= j);

    if (j > lewy) quicksort(tablica, lewy, j);
    if (i < prawy) quicksort(tablica, i, prawy);
}

int main()
{
    int t;
    //cout<<"Podaj liczbe testow: ";
    cin>>t;
    for(int i=0; i<t; i++)
    {
        //cout<<"Ile punktow chcesz wprowadzic: ";
        int n;
        cin>>n;
        Punkt* punkty = new Punkt [n];
        double* odleglosci = new double [n];
        for(int i=0; i<n; i++)
        {
            //cout<<"Podaj "<<i+1<<" punkt: ";
            cin>>punkty[i].nazwa>>punkty[i].x>>punkty[i].y;
            punkty[i].odleglosc = Odleglosc(punkty[i].x, punkty[i].y);
        }

        quicksort(punkty, 0, n-1);

        cout<<endl;
        //cout << "\nOdleglosci po sortowaniu:\n";
        for (int i = 0; i < n; i++)
        {
            cout << punkty[i].nazwa <<" " << punkty[i].x << " " <<punkty[i].y << "\n";

        }


        delete[] punkty;
        delete[] odleglosci;
    }
    return 0;
}
