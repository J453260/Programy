#include <iostream>
#include <cstring>
using namespace std;


template<typename T>
struct sum_traits
{
    typedef T total_type;
};

template<>
struct sum_traits<char>
{
    typedef int total_type;
};

template<>
struct sum_traits<int>
{
    typedef long long total_type;
};

template<>
struct sum_traits<float>
{
    typedef double total_type;
};


template<>
struct sum_traits<double>
{
    typedef long double total_type;
};

template<typename T>
typename sum_traits<T>::total_type sum(T *beg, T *end)
{
    typename sum_traits<T>::total_type total = typename sum_traits<T>::total_type();
    while (beg != end)
    {
        total += *beg;
        beg++;
    }
    return total;
}

/**
template<typename T> T sum(T *beg,T *end)
{
    T total = T();
    while(beg != end )
    {
        total += *beg;
        beg++;
    }
    cout<<total;
    return total;
}
*/

int main()
{
    char name[]="Hello World";
    int length=strlen(name);

    cout<<"Char: Hello World "<<sum(name, &name[length])<<endl;

    int inty[] = {1, 2, 3, 4, 5};
    //int length2=strlen(inty);
    cout<<"Inty: "<<sum(inty, &inty[5])<<endl;

    return 0;
}
