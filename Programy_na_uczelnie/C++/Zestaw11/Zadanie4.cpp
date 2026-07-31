// Demonstracja przeciążania szablonów funkcji z użyciem konceptów C++20
// oraz mechanizmu subsumpcji (concept subsumption) jako reguły
// rozstrzygającej przeciążenia.
// Kompilacja: g++ -std=c++20 Zadanie4.cpp -o Zadanie4

#include <concepts>
#include <iostream>

// Poziom 1: całkowicie nieograniczony szablon
void overload(auto t)
{

    std::cout << "auto : " << t << '\n';
}

// Poziom 2: ograniczony do typów całkowitych
void overload(std::integral auto t)
{

    std::cout << "Integral : " << t << '\n';
}

// Poziom 3: jeszcze bardziej szczegółowy - tylko int (subsumuje integral)
// wlasny koncept: int jest bardziej szczegolowy niz integral
template<typename T>
concept Int = std::integral<T> && std::same_as<T, int>;
 
void overload(Int auto t)
{
    std::cout << "Int (=int)  : " << t << '\n';
}

// Zwykła funkcja (nie-szablon) - zawsze preferowana przy remisie rangi
void overload(long t)
{
    std::cout<<"long: "<<t<<'\n';
}

int main()
{

    std::cout<<'\n';

    overload(3.14);
    overload(2010);
    overload(2020L);
    overload('A');

    // auto : 3.14
    // Int (=int)  : 2010
    // long: 2020
    // Integral : A
    
    std::cout<<'\n';
    return 0;
}