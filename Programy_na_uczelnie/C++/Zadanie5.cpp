#include <iostream>
using namespace std;

template<typename S> typename S::value_type f(S s) {
  typename S::value_type total = 0;
    /*
    słowo typename jest wymagane, inaczej kompilator założy, że 
    S::value_type odnosi się do statycznej składowej klasy
    */
  while(!s.isEmpty() ) {
    total+=s.pop();
  }
return total;
}

template <typename T>
struct Stack
{
    typedef T value_type;

    T data[100];
    T top = -1;

    void push(T val)
    {
        data[++top] = val;
    }

    T pop()
    {
        return data[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << f(s1) << endl;

    return 0;
}