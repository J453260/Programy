#include <iostream>
#include <string>
using namespace std;

template <typename T>
T convert(int x);

template <> int    convert<int>(int x)    { return x; }
template <> double convert<double>(int x) { return x*1.5; }
template <> string convert<string>(int x) { return to_string(x) + "World"; }

int main()
{
    int x = 10;
    //string x = "Hello";
    int    a = convert<int>(x);
    double b = convert<double>(x);
    string c = convert<string>(x);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}