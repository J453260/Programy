#include <iostream>
using namespace std;

template <typename T, int N>
class Stack
{
    // ogólna implementacja
    public:
    Stack()
    {
        cout << "Szablon bazowy: Stack<T, " << N << ">\n";
    }
};

template<typename T>
class Stack<T,666>
{
    public:
    Stack()
    {
        cout << "class Stack<T,666>" << endl;
    }
};

template<typename T,int N>
class Stack<T*,N>
{
    public:
    Stack()
    {
        cout << "class Stack<T*,N>" << endl;
    }
};

template<int N>
class Stack<double,N>
{
    public:
    Stack()
    {
        cout << "class Stack<double,N>" << endl;
    }
};

template<int N>
class Stack<int *,N>
{
    public:
    Stack()
    {
        cout << "class Stack<int *,N>" << endl;
    }
};

template<>
class Stack<double,666>
{
    public:
    Stack()
    {
        cout << "class Stack<double,666>" << endl;
    }
};

template<>
class Stack<double *,44>
{
    public:
    Stack()
    {
        cout << "class Stack<double *,44>" << endl;
    }
};

int main()
{
    Stack<int, 10>      s1;  // szablon bazowy
    Stack<int, 666>     s2;  // Stack<T, 666>
    Stack<int*, 5>      s3;  // Stack<T*, N>
    Stack<double, 5>    s4;  // Stack<double, N>
    Stack<int*, 5>      s5;  // Stack<int*, N>
    Stack<double, 666>  s6;  // Stack<double, 666>
    Stack<double*, 44>  s7;  // Stack<double*, 44>

    return 0;
}