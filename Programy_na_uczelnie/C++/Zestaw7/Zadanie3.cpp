#include<iostream>
using namespace std;

template<int X, int N>
struct Pow
{
    static constexpr int val = (N % 2 == 0) ? (Pow<X * X, N / 2>::val) : (X * Pow<X, N - 1>::val);
};

template<int X>
struct Pow<X, 0>
{
    static constexpr int val = 1;
};


int main()
{

    cout<<Pow<3,4>::val<<endl;// 81

    return 0;
}
