#include <iostream>
#include <cstring>
using namespace std;

template<typename Traits, typename T>
typename Traits::sum_type sum(T *beg, T *end)
{
    typedef typename Traits::sum_type sum_type;
    sum_type total = Traits::zero();

    while (beg != end)
    {
        total += *beg;
        beg++;
    }
    return total;
}

template<typename T>
struct sum_traits
{
    typedef T sum_type;
    static sum_type zero()
    {
        return sum_type();
    }
};

template<>
struct sum_traits<char>
{
    typedef int sum_type;
    static sum_type zero()
    {
        return 0;
    }
};

template<typename T>
typename sum_traits<T>::sum_type sum(T *beg, T *end)
{
    return sum<sum_traits<T>, T>(beg, end);
}

struct char_sum
{
    typedef int sum_type;
    static sum_type zero()
    {
        return 0;
    }
};

int main()
{
    char name[] = "@ @ @";
    int length = strlen(name);

    cout << (int)sum(name, &name[length]) << endl;
    cout << (int)sum<char_sum>(name, &name[length]) << endl;

    return 0;
}
