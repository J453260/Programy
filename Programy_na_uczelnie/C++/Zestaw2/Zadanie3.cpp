#include <iostream>
using namespace std;

template <class InputIterator, class T>
T accumulate(InputIterator first, InputIterator last, T init)
{
    T total=init;
    for( ; first != last; ++first)
    {
        total += *first;
    }
    return total;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int suma = accumulate(arr, arr+5, 0);
    cout<<suma<<endl;
    return 0;
}
