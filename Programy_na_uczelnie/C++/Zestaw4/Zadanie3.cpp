#include <iostream>
#include <cstring>
#include <iterator>
using namespace std;

// ===== traits domyślne =====
template<typename T>
struct sum_traits
{
    typedef T sum_type;
    static sum_type zero()
    {
        return sum_type();
    }
};

// specjalizacja dla char (sumujemy do int)
template<>
struct sum_traits<char>
{
    typedef int sum_type;
    static sum_type zero()
    {
        return 0;
    }
};

// ===== własne traits =====
struct sum_char
{
    typedef char sum_type;
    static sum_type zero()
    {
        return 0;
    }
};

// ===== główna funkcja =====
template<typename Traits, typename II>
typename Traits::sum_type sum(II beg, II end)
{
    typename Traits::sum_type total = Traits::zero();

    while (beg != end)
    {
        total += *beg;
        ++beg;
    }
    return total;
}

// ===== „domyślna” wersja =====
template<typename II>
typename sum_traits<typename iterator_traits<II>::value_type>::sum_type
sum(II beg, II end)
{
    typedef typename iterator_traits<II>::value_type value_type;
    return sum<sum_traits<value_type>>(beg, end);
}

// ===== MAIN =====
int main()
{
    char text[] = "@ @ @";
    int len = strlen(text);

    // 1. Domyślne traits (char -> int)
    cout << "Domyslne traits (int): "
         << sum(text, text + len) << endl;

    // 2. Własne traits (char -> char)
    cout << "Wlasne traits (char): "
         << (int)sum<sum_char>(text, text + len) << endl;

    // 3. Przykład dla int
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Int sum: "
         << sum(arr, arr + 5) << endl;

    return 0;
}
