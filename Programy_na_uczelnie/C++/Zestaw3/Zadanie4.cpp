// Kompilować z -std=c++17

#include <vector>
#include <iostream>

template<typename T,int N = 100, typename R = T*> class Stack;


template<typename T,int N> class Stack<T,N,T*>
{
    T _rep[N];
    unsigned int _top;
public:
    Stack():_top(0) {};
    void push(T e)
    {
        _rep[_top++]=e;
    }
    T pop()
    {
        return _rep[--_top];
    }
};

template<typename T,int N,template<typename E> class Sequence >
class Stack<T,N,Sequence<T> >
{
    Sequence<T> _rep;
public:
    void push(T e)
    {
        _rep.push_back(e);
    };
    T pop()
    {
        T top = _rep.back();
        _rep.pop_back();
        return top;
    }
    bool is_empty() const
    {
        return _rep.empty();
    }
};

int main()
{
    Stack<int,100,int *>            s_table;
    s_table.push(1);
    s_table.push(2);
    s_table.push(3);
    std::cout << "s_table: ";
    std::cout << s_table.pop() << " ";
    std::cout << s_table.pop() << " ";
    std::cout << s_table.pop() << std::endl;

    Stack<int,100>                  s_default;
    s_default.push(10);
    s_default.push(20);
    s_default.push(30);
    std::cout << "s_default: ";
    std::cout << s_default.pop() << " ";
    std::cout << s_default.pop() << " ";
    std::cout << s_default.pop() << std::endl;

    Stack<int,0,std::vector<int> >  s_container;
    s_container.push(100);
    s_container.push(200);
    s_container.push(300);
    std::cout << "s_container: ";
    while (!s_container.is_empty())
    {
        std::cout << s_container.pop() << " ";
    }
    std::cout << std::endl;
    return 0;
}
