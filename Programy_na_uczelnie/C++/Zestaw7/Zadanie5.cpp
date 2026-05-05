#include <iostream>
#include <vector>
using namespace std;

template<size_t N> double inner(double *x, double *y)
{
    double wynik = 0.0;
    for(size_t i=0; i<N; i++)
    {
        wynik += x[i] * y[i];
    }
    return wynik;
}

int main()
{
    double v1[] = {1.0, 2.0, 3.0};
    double v2[] = {4.0, 5.0, 6.0};

    cout<<inner<3>(v1, v2)<<endl; // 32
}
