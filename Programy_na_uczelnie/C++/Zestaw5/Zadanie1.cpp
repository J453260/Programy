#include<vector>
#include<iostream>
using namespace std;

template<typename T> class Is_class
{
    /* najpierw definiujemy dwa typy różniące sie rozmiarem */
    typedef char one;
    typedef struct
    {
        char c[2];
    } two;
    /* teraz potrzebne będą dwa przeładowane szablony */
    template<typename U> static one test(int U::* );
    template<typename U> static two test(...);

    /* to który szablon został wybrany sprawdzamy poprzez
       sprawdzenie rozmiaru zwracanego typu */
public:
    enum {yes = (sizeof(test<T>(0))==sizeof(one) )};
};


struct X {};

int main()
{

    cerr<<Is_class<int>::yes<<endl;
    cerr<<Is_class<X>::yes<<endl;
    cerr<<Is_class<vector<double> >::yes<<endl;

    return 0;
}
