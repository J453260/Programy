#include <iostream>
using namespace std;

template<size_t N,typename T> T dot_product(T *a,T *b) 
{
    T total=0.0;
    for(size_t i=0;i<N;++i)
    {
        total += a[i]*b[i];
    }

    return total;
};

int main()
{
    double a[] = {1.0, 2.0, 3.0};
    double b[] = {4.0, 5.0, 6.0};

    double wynik = dot_product<3, double>(a, b);

    return 0;
}
