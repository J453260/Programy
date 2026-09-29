#include <iostream>
#include <cmath>
#include "PrzydatneFunkcje.h"
using namespace std;

bool CzyMaPierwiastek(int a)
{
    int b = sqrt(a);
    if(b*b == a)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Trojki(int dol, int gora)
{
    int licznik = 0;
    for(int i = dol; i<= gora; i++)
    {
        for(int j = i; j<= gora; j++)
        {
            int z;
            z = i*i + j*j;
            if(CzyMaPierwiastek(z))
            {
                cout<<i<<" "<<j<<" "<<sqrt(z)<<endl;
                licznik++;
            }
        }
    }

    cout<<endl<<"Jest ich: "<<licznik;
}

int NWD(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long NWW(int a, int b){
    return (long)a / NWD(a, b) * b;
}

void drawSus()
{
    cout << "                       ###                                          " << endl;
    cout << "                    #######################                         " << endl;
    cout << "                #######                  ######                     " << endl;
    cout << "                #####                      ####                     " << endl;
    cout << "                ####              ################                  " << endl;
    cout << "                ####              #################                 " << endl;
    cout << "       #############             ####            ####               " << endl;
    cout << "     ################          #####               ####             " << endl;
    cout << "      ###         ###         #####                #####            " << endl;
    cout << "      ###         ###         #####                   ###           " << endl;
    cout << "      ###         ###         ########             #######          " << endl;
    cout << "     ###          ###             ########    ############          " << endl;
    cout << "      ###         ###               ######################          " << endl;
    cout << "      ###         ###                                  ###          " << endl;
    cout << "      ###         ###                                  ###          " << endl;
    cout << "      ###         ###                                  ###          " << endl;
    cout << "      ###        ###                                   ###          " << endl;
    cout << "      ###         ###                                  ###          " << endl;
    cout << "      ###         ###                                  ###          " << endl;
    cout << "     ################                                  ###          " << endl;
    cout << "         #############                                 ###          " << endl;
    cout << "                  ###                                  ###          " << endl;
    cout << "                  ###             #########            ###          " << endl;
    cout << "                  ###           ###       ###          ###          " << endl;
    cout << "                  ###          ###         ###         ###          " << endl;
    cout << "                 ###           ###          ###        ###          " << endl;
    cout << "                  ###          ###          ###        ###          " << endl;
    cout << "                   ###         ###          ###       ###           " << endl;
    cout << "                     ###       ###          ###      ###            " << endl;
    cout << "                      ############          #########               " << endl;
}

long long SymbolNewtona(int n, int k)
{
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;

    if (k > n - k)
    {
        k = n - k;
    }

    long long wynik = 1;
    for (int i = 1; i <= k; ++i)
    {
        wynik *= (n - i + 1);
        wynik /= i;
    }

    return wynik;
}
