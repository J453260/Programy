#include <iostream>
using namespace std;

int dodaj(int a, int b)
{
    return a + b;
}

double dodaj(double a, double b)
{
    return a + b;
}

int main()
{
    dodaj(3.14, 2.71);
    dodaj(1, 2);

    return 0;
}