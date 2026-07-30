#include <iostream>
#include "dziedziczenie.h"
#include "checking_policy.h"
//#include "allocator2.h"

int main()
{
    // Stack<int,100> dziedziczy prywatnie po Static_table_allocator<int,100>
    Stack<int,5> s;

    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "top: " << s.top() << std::endl;   // 3

    s.pop();
    std::cout << "top po pop: " << s.top() << std::endl;   // 2

    s.top() = 99;                                    // modyfikacja przez referencje
    std::cout << "top po modyfikacji: " << s.top() << std::endl;   // 99

    std::cout << "empty? " << std::boolalpha << s.is_empty() << std::endl;

    return 0;
}