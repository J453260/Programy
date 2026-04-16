#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template<typename T>
struct sum_traits
{
    typedef T sum_type;

    static sum_type zero()
    {
        return sum_type();
    }
};

template<typename II>
typename sum_traits<typename std::iterator_traits<II>::value_type>::sum_type
sum(II beg, II end)
{
    typedef typename std::iterator_traits<II>::value_type value_type;
    typedef typename sum_traits<value_type>::sum_type sum_type;

    sum_type total = sum_traits<value_type>::zero();

    while (beg != end)
    {
        total += *beg;
        ++beg;
    }
    return total;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << sum(arr, arr + 5) << endl;

    vector<int> v = {10, 20, 30};
    cout << sum(v.begin(), v.end()) << endl;

    return 0;
}
