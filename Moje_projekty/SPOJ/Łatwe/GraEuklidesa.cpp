#include <iostream>
using namespace std;

int main()
{
    int t;
    //cout<<"Podaj liczbe testow: ";
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int r1, r2;
        //cout<<"Podaj 2 liczby: ";
        cin>>r1>>r2;
        while(r1!=r2)
        {
            if(r1>r2)
            {
                r1 = r1 - r2;
            }
            else
            {
                r2 = r2 - r1;
            }
        }
        cout<<r1+r2<<endl;
    }

    return 0;
}
