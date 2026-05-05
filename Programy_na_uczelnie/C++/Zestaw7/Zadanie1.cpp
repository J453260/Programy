#include<iostream>
using namespace std;

template<int K> struct Silnia
{
    enum {val=K*Silnia<K-1>::val};
};

template<> struct Silnia<0>
{
    enum {val=1};
};


int main()
{
    cout<<"3! = "<< Silnia<3>::val <<endl;// 6
    cout<<"8! = "<< Silnia<8>::val <<endl;// 40320

    return 0;
}
