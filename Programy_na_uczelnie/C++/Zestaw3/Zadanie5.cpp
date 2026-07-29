#include <vector>
#include <iostream>
#include <set>

template<class T = void>
struct less
{
    bool operator()(const T& a, const T& b) const
    {
        return a < b;
    }
};

template<class T = void>
struct less_equal
{
    bool operator()(const T& a, const T& b) const
    {
        return a <= b;
    }
};

template<class T = void>
struct greater
{
    bool operator()(const T& a, const T& b) const
    {
        return a > b;
    }
};

template<class T = void>
struct greater_equal
{
    bool operator()(const T& a, const T& b) const
    {
        return a >= b;
    }
};

int main()
{
    std::set<int> zbior1 = {5, 4, 3, 2, 1};
    std::set<int> zbior2 = {1, 2, 3, 4, 5};

    bool wynik = less<std::set<int>>()(zbior1, zbior2);

    std::cout << std::boolalpha;
    std::cout << "less:          " << less<std::set<int>>()(zbior1, zbior2)          << std::endl;
    std::cout << "less_equal:    " << less_equal<std::set<int>>()(zbior1, zbior2)    << std::endl;
    std::cout << "greater:       " << greater<std::set<int>>()(zbior1, zbior2)       << std::endl;
    std::cout << "greater_equal: " << greater_equal<std::set<int>>()(zbior1, zbior2) << std::endl;

    return 0;
}
