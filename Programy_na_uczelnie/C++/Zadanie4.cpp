#include <iostream>
using namespace std;
template< template<int N> class  C,int K>
/*
taka definicja oznacza, że parametr C określa szablon klasy 
posiadający jeden parametr typu int. Parametr N służy tylko 
do definicji szablonu C i nie może być użyty nigdzie indziej
*/
void f(C<K>){
  cout<<K<<endl;
};

template<int N> struct SomeClass {};

main() {
  SomeClass<1>  c1;
  SomeClass<2>  c2;

  f(c1); //C=SomeClass K=1
  f(c2); //C=SomeClass K=2
}