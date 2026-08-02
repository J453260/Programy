#include <iostream>
using namespace std;

int main()
{
    char operacja;
    int liczba1, liczba2;
    while(cin>>operacja>>liczba1>>liczba2)
    {
        switch(operacja)
        {
        case '+':
        {
            cout<<liczba1+liczba2<<endl;
            break;
        }
        case '-':
        {
            cout<<liczba1-liczba2<<endl;
            break;
        }
        case '*':
        {
            cout<<liczba1*liczba2<<endl;
            break;
        }
        case '/':
        {
            cout<<liczba1/liczba2<<endl;
            break;
        }
        case '%':
        {
            cout<<liczba1%liczba2<<endl;
            break;
        }
        }
    }
    return 0;
}
