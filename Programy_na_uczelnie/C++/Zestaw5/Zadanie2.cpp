#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<typename T>
class has_value_type
{
    typedef char one;
    typedef struct
    {
        char c[2];
    } two;

    template<typename U> static one test(typename U::value_type*);
    template<typename U> static two test(...);

public:
    enum { yes = (sizeof(test<T>(0)) == sizeof(one)) };
};

int main()
{
    cerr << has_value_type<int>::yes             << endl;
    cerr << has_value_type<vector<int>>::yes     << endl;
    cerr << has_value_type<map<int,int>>::yes    << endl;
    cerr << has_value_type<double>::yes          << endl;
}


/*
Wynik:
0
1
1
0
*/
