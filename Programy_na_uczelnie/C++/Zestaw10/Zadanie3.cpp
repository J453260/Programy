#include <iostream>
#include <vector>
#include <algorithm>

namespace my
{

template<typename InputIt, typename OutputIt, typename T>
OutputIt replace_copy(InputIt first, InputIt last, OutputIt d_first, const T& old_value, const T& new_value)
{
    while (first != last)
    {
        *d_first = (*first == old_value) ? new_value : *first;
        ++first;
        ++d_first;
    }
    return d_first;
}

template<typename InputIt, typename T>
InputIt find(InputIt first, InputIt last, const T& value)
{
    while (first != last)
    {
        if(*first == value)
        {
            return first;
        }
        ++first;
    }

    return last;
}

template<typename InputIt, typename OutputIt>
OutputIt move(InputIt first, InputIt last, OutputIt d_first)
{
    while (first != last)
    {
        *d_first = std::move(*first);
        ++first;
        ++d_first;
    }
    return d_first;
}

template<typename InputIt, typename UnaryFunc>
UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
{
    while (first != last)
    {
        f(*first);
        ++first;
    }
    return f;
}

template<typename ForwardIt, typename T>
ForwardIt remove(ForwardIt first, ForwardIt last, const T& value)
{
    ForwardIt result = first;
    while (first != last)
    {
        if (*first != value)
        {
            *result = std::move(*first);
            ++result;
        }
        ++first;
    }
    return result;
}

}

int main()
{
    // replace_copy
    std::vector<int> src1 = {1, 2, 3, 2, 4, 2, 5};
    std::vector<int> dst(src1.size());
    my::replace_copy(src1.begin(), src1.end(), dst.begin(), 2, 99);
    for (int x : dst)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // find
    std::vector<int> src2 = {1, 2, 3, 2, 4, 2, 5};
    auto it = my::find(src2.begin(), src2.end(), 2);
    if (it != src2.end())
    {
        std::cout << "Znaleziono: " << *it << "\n";
    }

    // move
    std::vector<int> src3 = {1, 2, 3, 2, 4, 2, 5};
    std::vector<int> src4(src3.size());
    my::move(src3.begin(), src3.end(), src4.begin());
    for (int x : src4)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // for_each
    std::vector<int> src5 = {1, 2, 3, 2, 4, 2, 5};
    my::for_each(src5.begin(), src5.end(), [](int x){ std::cout << x << " "; });
    std::cout << "\n";

    // remove
    std::vector<int> src6 = {1, 2, 3, 2, 4, 2, 5};
    auto new_end = my::remove(src6.begin(), src6.end(), 4);
    src6.erase(new_end, src6.end());
    for (int x : src6)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
