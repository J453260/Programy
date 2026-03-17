#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int Losuj(int m1, int m2)
{
    int number = m1+ rand() % (m2 - m1 + 1);
    return number;
}

void Slowa(int liczba, int m1, int m2)
{
    int dlugosc;
    for(int i=0; i<liczba; i++)
    {
        dlugosc = Losuj(m1, m2);
        string slowo = "";
        for(int i=0; i<dlugosc; i++)
        {
            slowo += 'a' + rand() % 26;
        }
        cout<<slowo<<endl;
    }
}

void Panel()
{
    srand(time(nullptr));
    int liczba, m1, m2;
    cout<<"Ile slow chcesz wygenerowac: ";
    cin>>liczba;
    cout<<"Jakiej dlugosci slowa chcesz generowac?"<<endl;
    cout<<"Podaj przedzial: ";
    cin>>m1>>m2;
    cout<<endl;
    Slowa(liczba, m1, m2);
}

int main()
{
    Panel();
    return 0;
}
