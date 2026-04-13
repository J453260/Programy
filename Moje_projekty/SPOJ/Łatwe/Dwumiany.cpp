#include <iostream>
#include <cmath>
using namespace std;

int SymbolNewtona(int a, int b)
{
    if(a==0 && b==0)
    {
        return 1;
    }

    if(b>a)
    {
        return 0;
    }

    b = min(b, a - b);

    long long wynik = 1;
    for(int i = 1; i <= b; i++)
    {
        wynik = wynik * (a - b + i) / i;
    }

    return wynik;
}

int main()
{
    int T;
    //cout<<"Podaj liczbe testow: ";
    cin>>T;
    for(int i=0; i<T; i++)
    {
        int n,k;
        //cout<<"Podaj n i k: ";
        cin>>n>>k;
        cout<<SymbolNewtona(n, k)<<endl;
    }
    return 0;
}
