#include <iostream>
using namespace std;

int FunkcjaCollatza(int s, int n)
{
    int x_n = s;

    if(x_n == 1)
    {
        return n;
    }

    if(x_n % 2 == 1)
    {
        return FunkcjaCollatza(3*x_n + 1, n+1);
    }
    else
    {
        return FunkcjaCollatza(x_n / 2, n+1);
    }
}

int main()
{
    int t;
    //cout<<"Podaj liczbe testow: ";
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int s;
        //cout<<"Podaj s: ";
        cin>>s;
        cout << FunkcjaCollatza(s, 0) << endl;
    }

    return 0;
}
