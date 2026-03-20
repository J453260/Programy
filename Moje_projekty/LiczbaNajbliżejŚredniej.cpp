#include <iostream>
#include <cmath> //dla fabs
using namespace std;

//5 3 7 2 6 -> 4,6 -> 0,4 1,6 2,4 2,6 1,4

float a,b,c,d,e,m,s,f,g,h,i,j,z;
//m srednia
//s suma
//f najmniejsza liczba
int main()
{
	cout<<"Podaj 5 liczb oddzielonych spacja: ";
	cin>>a>>b>>c>>d>>e;
	s=a+b+c+d+e;
	m=s/5;
	cout<<"Srednia podanych liczb to: "<<m<<endl;
	
	f=fabs(a-m);
	g=fabs(b-m);
	h=fabs(c-m);
	i=fabs(d-m);
	j=fabs(e-m);
	
	z=f;
	if (z>g) z=g;
	if (z>h) z=h;
	if (z>i) z=i;
	if (z>j) z=j;

	cout<<"Liczba najblizej sredniej to: "<<m+z;

	return 0;
}
