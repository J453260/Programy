#include <iostream>
using namespace std;

const int MAX = 100;
int kolejka[MAX];
int poczatek=0;
int koniec=0;

bool isEmpty()
{
    return poczatek == koniec;
}
bool full()
{
    return (koniec + 1) % MAX == poczatek;
}
void dodaj(int elem)
{
    if (full())
    {
        cout << "Kolejka pelna!" << endl;
        return;
    }
    kolejka[koniec] = elem;
    koniec = (koniec + 1) % MAX;
}

int usun()
{
    if (isEmpty())
    {
        cout << "Kolejka pusta!" << endl;
        return -1;
    }
    int elem = kolejka[poczatek];
    poczatek = (poczatek + 1) % MAX;
    return elem;
}
void Wyswietl()
{
    if (isEmpty())
    {
        cout << "Kolejka pusta" << endl;
        return;
    }
    cout << "Elementy kolejki:" << endl;
    for (int i = poczatek; i != koniec; i = (i + 1) % MAX) cout << kolejka[i] << " ";
    cout << endl;
}
void rozmiarKolejki()
{
    cout << (koniec - poczatek + MAX) % MAX << endl;
}
int main ()
{
    while(true)
    {
        char pol;
        cout<< "wcisnij : d - dodaj , u - usun , r - rozmiar , q - zakoncz program , w - wyswietl zawartosc kolejki" <<endl;
        cin>>pol;
        int elem;
        if (pol=='d')
        {
            cout<<"Jaki element chcesz dodac: ";
            cin>>elem;
            dodaj(elem);
        }
        if(pol=='u')
        {
            Wyswietl();
            cout<<"Jaki element chcesz usunac: ";
            cin>>elem;
            cout<<"Usunieto: "<<usun()<<endl;
        }
        if(pol=='r')
        {
            rozmiarKolejki();
        }

        if(pol=='q')
        {
            break;
        }
        if(pol=='w')
        {
            Wyswietl();
        }

        cout<<endl;
    }

    return 0;
}
