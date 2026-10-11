#include <iostream>
using namespace std;

int main()
{
    int t;
    if (!(cin >> t)) return 0;
    //cout<<"Podaj liczbe testow: ";
    //cin>>t;

    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        cout<<n*n<<endl;
    }

    return 0;
}
