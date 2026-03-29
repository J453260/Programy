#include <iostream>
#include <cmath> //dla fabs
using namespace std;

float LiczbaNajblizejSredniej(float a, float b, float c, float d, float e)
{
    float m,s,f,g,h,i,j,z,liczba;
    s=a+b+c+d+e;
	m=s/5;
	cout<<"Srednia podanych liczb to: "<<m<<endl;

	f=fabs(a-m);
	g=fabs(b-m);
	h=fabs(c-m);
	i=fabs(d-m);
	j=fabs(e-m);

	z=f;
	liczba=a;
	if (z>g)
    {
        z=g;
        liczba=b;
    }
	if (z>h)
    {
        z=h;
        liczba=c;
    }
	if (z>i)
	{
        z=g;
        liczba=d;
    }
	if (z>j)
	{
        z=g;
        liczba=e;
    }

	cout<<"Liczba najblizej sredniej to: "<<liczba<<endl;

	return liczba;
}
//m srednia
//s suma
//z najmniejsza liczba
int main()
{
	cout<<"Podaj 5 liczb oddzielonych spacja: ";
	cin>>a>>b>>c>>d>>e;
	cout<<"Liczba najblizej sredniej to: "<<LiczbaNajblizejSredniej(a, b, c, d, e);

	return 0;
}
