#include <iostream>
using namespace std;

template <typename To, typename From>
To convert(From value) {
    return static_cast<To>(value);
}

int main() 
{
    double d = convert<double>(42);      // int → double
    int i = convert<int>(3.99);          // double → int (ucina)
    char c = convert<char>(65);          // int → char (ASCII)
    
    cout << d << endl;  // 42
    cout << i << endl;  // 3
    cout << c << endl;  // A

    return 0;
}
