#include <iostream>
#include <cstring>
using namespace std;

bool PESEL(string NumerPESEL)
{
    int dlugosc = NumerPESEL.length();
    if(dlugosc != 11)
    {
        return false;
    }

    int liczba[dlugosc];
    for(int i=0; i<dlugosc; i++)
    {
        liczba[i] = NumerPESEL[i] - '0';
    }

    int x;
    x = liczba[0]*1 + liczba[1]*3 + liczba[2]*7 + liczba[3]*9 + liczba[4]*1 + liczba[5]*3 + liczba[6]*7 + liczba[7]*9 + liczba[8]*1 + liczba[9]*3 + liczba[10]*1;

    if(x%10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int t;
    //cout<<"Podaj liczbe numerow PESEL: ";
    cin>>t;
    for(int i=0; i<t; i++)
    {
        //cout<<"Podaj "<<i+1<< " PESEL: ";
        string NumerPESEL;
        cin>>NumerPESEL;
        if(PESEL(NumerPESEL))
        {
            cout<<"D"<<endl;
        }
        else
        {
            cout<<"N"<<endl;
        }
    }

    return 0;
}
