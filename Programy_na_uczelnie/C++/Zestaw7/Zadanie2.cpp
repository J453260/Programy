#include<iostream>
using namespace std;


template<int  N> struct Pow3
{
    enum {val=3*Pow3<N-1>::val};
};

template<> struct Pow3<0>
{
    enum {val=1};
};


template<int K,int  N> struct Pow
{
    enum {val=K*Pow<K,N-1>::val};
};

template<int K> struct Pow<K,0>
{
    enum {val=1};
};


int main()
{
    cout<< Pow3<4>::val <<endl;//81
    cout<< Pow<3,4>::val <<endl;//81
    cout<< Pow<2,8>::val <<endl;//256

    return 0;
}
