// Demonstracja trzech podstawowych execution policies z C++17
// Kompilacja (GCC wymaga TBB dla par/par_unseq):
//   g++ -std=c++17 execution_policies.cpp -o exec_demo -ltbb

#include <algorithm>
#include <execution>
#include <vector>
#include <numeric>
#include <chrono>
#include <cmath>
#include <iostream>

// Prosty pomiar czasu wykonania podanej funkcji
template<typename F>
double measure(F func)
{
    auto start = std::chrono::steady_clock::now();
    func();
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(end - start).count();
}

int main()
{
    const size_t N = 20'000'000;
    std::vector<double> base(N);
    std::iota(base.begin(), base.end(), 1.0);

    // ------------------------------------------------------------------
    // 1) std::execution::seq  -  wykonanie SEKWENCYJNE
    //    - zachowuje kolejność operacji (deterministyczne)
    //    - brak wielowątkowości, brak wektoryzacji
    //    - używać, gdy kolejność ma znaczenie (np. efekty uboczne,
    //      wypisywanie) lub dane są za małe by opłacało się zrównoleglać
    // ------------------------------------------------------------------
    {
        auto v = base;
        double t = measure([&]{
            std::transform(std::execution::seq, v.begin(), v.end(), v.begin(), [](double x) { return std::sqrt(x) * std::sin(x); });
        });
        std::cout << "seq       : " << t << " s\n";
    }

    // ------------------------------------------------------------------
    // 2) std::execution::par  -  wykonanie RÓWNOLEGŁE (wielowątkowe)
    //    - biblioteka MOŻE rozdzielić prace na wiele watkow
    //    - kolejnosc wykonania miedzy watkami NIE jest gwarantowana
    //    - funkcja przekazana MUSI byc bezpieczna wielowatkowo
    //      (bez wyscigow danych - modyfikacja wspoldzielonego stanu
    //       bez synchronizacji jest bledem)
    //    - oplacalne dla duzych zbiorow danych / kosztownych operacji
    // ------------------------------------------------------------------
    {
        auto v = base;
        double t = measure([&]{
            std::transform(std::execution::par, v.begin(), v.end(), v.begin(),
                [](double x) { return std::sqrt(x) * std::sin(x); });
        });
        std::cout << "par       : " << t << " s\n";
    }

    // ------------------------------------------------------------------
    // 3) std::execution::par_unseq  -  RÓWNOLEGŁE + WEKTORYZOWANE (SIMD)
    //    - dodatkowo pozwala na przeplatanie instrukcji z roznych
    //      "iteracji" w obrebie jednego watku (wektoryzacja)
    //    - funkcja NIE MOZE: alokowac pamieci, blokowac mutexow,
    //      rzucac wyjatkow ani wywolywac czegokolwiek co to robi
    //    - najlepsze dla prostych operacji numerycznych bez efektow
    //      ubocznych na duzych zbiorach danych
    // ------------------------------------------------------------------
    {
        auto v = base;
        double t = measure([&]{
            std::transform(std::execution::par_unseq, v.begin(), v.end(), v.begin(), [](double x) { return std::sqrt(x) * std::sin(x); });
        });
        std::cout << "par_unseq : " << t << " s\n";
    }

    return 0;
}