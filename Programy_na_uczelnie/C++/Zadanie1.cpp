#include <iostream>
using namespace std;

template <typename T>
T maximum(T a, T b) {
    return (a < b) ? b : a;
}

int main(){
    cout<<maximum(7, 3)<<endl;
    cout<<maximum(2.71, 3.14)<<endl;
    cout<<maximum("a", "z")<<endl;

    return 0;

}

/*
Zaimplementuj szablon funkcji maksimum() , wybierającej większy z dwóch argumentów.
Argumenty są jednakowego typu i posiadają operator< .
*/
