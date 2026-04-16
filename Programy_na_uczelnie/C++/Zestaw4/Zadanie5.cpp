#include <iostream>
#include <iterator>
#include <vector>
#include <list>
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

template<typename II, typename T>
T sum_impl(II beg, II end, std::random_access_iterator_tag)
{
    T total = sum_traits<T>::zero();

    for (II it = beg; it != end; ++it)
        total += *it;

    return total;
}

template<typename II, typename T>
T sum_impl(II beg, II end, std::bidirectional_iterator_tag)
{
    T total = sum_traits<T>::zero();

    while (beg != end)
    {
        total += *beg;
        ++beg;
    }

    return total;
}

template<typename II, typename T>
T sum_impl(II beg, II end, std::input_iterator_tag)
{
    T total = sum_traits<T>::zero();

    while (beg != end)
    {
        total += *beg;
        ++beg;
    }

    return total;
}

template<typename II>
typename sum_traits<typename std::iterator_traits<II>::value_type>::sum_type
sum(II beg, II end)
{
    typedef typename std::iterator_traits<II>::value_type value_type;
    typedef typename sum_traits<value_type>::sum_type sum_type;

    return sum_impl<II, sum_type>(
               beg,
               end,
               typename std::iterator_traits<II>::iterator_category()
           );
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << sum(arr, arr + 5) << endl;

    vector<int> v = {10, 20, 30};
    cout << sum(v.begin(), v.end()) << endl;

    list<int> l = {1, 2, 3, 4};
    cout << sum(l.begin(), l.end()) << endl;

    return 0;
}
