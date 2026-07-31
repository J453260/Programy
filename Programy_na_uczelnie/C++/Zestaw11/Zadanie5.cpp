#include <iostream>
#include <concepts>

template<typename T>
requires requires(T a, T b)
{
    {
        a + b
    }
    -> std::same_as<T>;
}
void f(T a, T b)
{
    std::cout << "Suma: " << a + b;
}

int main()
{
    int x = 5;
    int p = 7;

    f(x, p);
}