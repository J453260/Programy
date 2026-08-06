#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        string slowo;
        cin>>slowo;
        int l = slowo.size();
        for(int i=0; i<l/2; i++)
        {
            cout<<slowo[i];
        }
        cout<<endl;
    }
    return 0;
}
