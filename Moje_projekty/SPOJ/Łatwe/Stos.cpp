#include <iostream>
using namespace std;

const int ROZMIAR = 10;

int main()
{
    int stos[ROZMIAR];
    int wierzcholek = 0;
    char operacja;
    while(cin>>operacja)
    {
        switch(operacja)
        {
        case '+':
        {
            int liczba;
            cin>>liczba;

            if(wierzcholek < ROZMIAR)
            {
                stos[wierzcholek] = liczba;
                wierzcholek++;
                cout<<":)"<<endl;
            }
            else
            {
                cout<<":("<<endl;
            }
            break;
        }

        case '-':
        {
            if(wierzcholek > 0)
            {
                wierzcholek--;
                cout << stos[wierzcholek] << endl;
            }
            else
            {
                cout<<":("<<endl;
            }
            break;
        }
        default:
            cout << ":(" << endl;
        }
    }
    return 0;
}
