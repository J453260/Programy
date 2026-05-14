#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout<<"A"<<endl;
    }

    ~A()
    {
        cout<<"~A"<<endl;
    }
};


class B
{
public:
    B()
    {
        cout<<"B"<<endl;
    }

    ~B()
    {
        cout<<"~B"<<endl;
    }
};


A func()
{
    B b;
    return A();
}

int main()
{
    A a = func();

    return 0;
}
