#include <iostream>
using namespace std;

int main()
{
    int t;
    //cout<<"Podaj liczbe testow: ";
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n;
        //cout<<"Podaj n i n liczb: ";
        cin>>n;
        int* tablica = new int [n];
        for(int i=0; i<n; i++)
        {
            cin>>tablica[i];
        }

        int pierwszy = tablica[0];
        for(int i=1; i<n; i++)
        {
            tablica[i-1] = tablica[i];
        }

        tablica[n-1] = pierwszy;

        for(int i=0; i<n; i++)
        {
            cout<<tablica[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
