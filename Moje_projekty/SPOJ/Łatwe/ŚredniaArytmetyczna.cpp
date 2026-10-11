#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
using namespace std;

float LiczbaNajblizejSredniej(const int liczby[], int rozmiar)
{
    float s = 0.0;
    for(int i = 0; i<rozmiar; i++)
    {
        s+=liczby[i];
    }

	float m=s/rozmiar;
	vector<float> roznice;

	for(int i = 0; i<rozmiar; i++)
    {
        roznice.push_back(fabs(liczby[i]-m));
    }

	float minRoznica = roznice[0];
	int index = 0;

	for(size_t i=0; i<roznice.size(); i++)
    {
        if(minRoznica>roznice[i])
        {
            minRoznica=roznice[i];
            index = i;
        }
    }

	return liczby[index];
}

int main()
{
    int t;
    if (!(cin >> t)) return 0;
    //cout<<"Podaj liczbe testow: ";
    //cin>>t;

    for(int i=0; i<t; i++)
    {
        int n;
        //cout<<"Podaj n: ";
        cin>>n;
        int* liczby = new int[n];
        //cout<<"Podaj liczby oddzielonych spacja: ";

        for(int j=0; j<n; j++)
        {
            cin>>liczby[j];
        }
        cout<<LiczbaNajblizejSredniej(liczby, n)<<endl;

        delete[] liczby;
    }

    return 0;
}
