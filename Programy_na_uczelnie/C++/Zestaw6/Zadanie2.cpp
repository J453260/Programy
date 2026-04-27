#include <iostream>
#include <stdexcept>
#include <cstdlib>

// POLITYKI SPRAWDZANIA

struct No_checking_policy
{
    static void check_push(size_t, size_t) {}
    static void check_pop(size_t) {}
    static void check_top(size_t) {}
};

struct Abort_on_error_policy
{
    static void check_push(size_t top, size_t size)
    {
        if (top >= size)
        {
            std::cerr << "Trying to push element on full stack: aborting\n";
            abort();
        }
    }
    static void check_pop(size_t top)
    {
        if (top == 0)
        {
            std::cerr << "Trying to pop an empty stack: aborting\n";
            abort();
        }
    }
    static void check_top(size_t top)
    {
        if (top == 0)
        {
            std::cerr << "Trying to read from empty stack: aborting\n";
            abort();
        }
    }
};

struct Std_exception_on_error_policy
{
    static void check_push(size_t top, size_t size)
    {
        if (top >= size)
            throw std::range_error("over the top");
    }
    static void check_pop(size_t top)
    {
        if (top == 0)
            throw std::range_error("poping empty");
    }
    static void check_top(size_t top)
    {
        if (top == 0)
            throw std::range_error("reading empty");
    }
};

// SZABLON KLASY STACK

template<typename T = int, size_t N = 100,
         typename Checking_policy = No_checking_policy>
class Stack
{
    T      _rep[N];
    size_t _top;
public:
    Stack() : _top(0) {}

    void push(const T& val)
    {
        Checking_policy::check_push(_top, N);
        _rep[_top++] = val;
    }
    void pop()
    {
        Checking_policy::check_pop(_top);
        --_top;
    }
    const T& top() const
    {
        Checking_policy::check_top(_top);
        return _rep[_top - 1];
    }
    T& top()
    {
        Checking_policy::check_top(_top);
        return _rep[_top - 1];
    }
    bool is_empty() const
    {
        return _top == 0;
    }
};

int main()
{
    Stack<int, 10>                                 s_no_check;
    std::cout << "Utworzono Stack<int,10> z domyslna polityka No_checking_policy\n";

    Stack<double, 100, Abort_on_error_policy>      s_abort;
    std::cout << "Utworzono Stack<double,100> z polityka Abort_on_error_policy\n";

    Stack<int*, 25, Std_exception_on_error_policy> s_except;
    std::cout << "Utworzono Stack<int*,25> z polityka Std_exception_on_error_policy\n";

    return 0;
}
