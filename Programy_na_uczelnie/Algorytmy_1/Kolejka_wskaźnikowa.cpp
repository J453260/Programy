#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

Node* poczatek = nullptr;
Node* koniec   = nullptr;

bool isEmpty()
{
    return poczatek == nullptr;
}

void dodaj(int elem)
{
    Node* nowy = new Node;

    nowy->value = elem;
    nowy->next = nullptr;

    if (isEmpty())
    {
        koniec = nowy;
        poczatek = nowy;
    }
    else
    {
        koniec->next = nowy;
        koniec = nowy;
    }
}

int usun()
{
    if (isEmpty())
    {
        cout << "Kolejka pusta!" << endl;
        return -1;
    }

    Node* temp = poczatek;
    int wartosc = temp->value;

    poczatek = poczatek->next;

    if (poczatek == nullptr)
        koniec = nullptr;

    delete temp;
    return wartosc;
}

void Wyswietl()
{
    if (isEmpty())
    {
        cout << "Kolejka pusta" << endl;
        return;
    }

    cout << "Elementy kolejki:" << endl;

    Node* temp = poczatek;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void rozmiarKolejki()
{
    int licznik = 0;
    Node* temp = poczatek;

    while (temp != nullptr)
    {
        licznik++;
        temp = temp->next;
    }

    cout << licznik << endl;
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
            cout<<"Usunieto: "<<usun()<<endl;
        }

        if(pol=='r')
        {
            rozmiarKolejki();
        }

        if(pol=='w')
        {
            Wyswietl();
        }

        if(pol=='q')
        {
            break;
        }

        cout<<endl;
    }
    return 0;
}
