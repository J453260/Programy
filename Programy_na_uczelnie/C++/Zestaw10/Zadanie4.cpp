// Krótki przegląd algorytmów C++17 z <algorithm> i <numeric>
// Kompilacja: g++ -std=c++17 algorithms_overview.cpp -o algo_demo

#include <algorithm>
#include <numeric>
#include <execution>
#include <vector>
#include <string>
#include <iostream>

void print(const std::string& label, const std::vector<int>& v)
{
    std::cout << label << ": ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}

void foreach()
{
    // ------------------------------------------------------------
    // std::for_each  -  wywołuje funkcję na KAŻDYM elemencie zakresu
    // (podstawowa wersja, cały zakres [first, last))
    // ------------------------------------------------------------
    {
        std::vector<int> v {1, 2, 3, 4, 5};
        std::for_each(v.begin(), v.end(), [](int& x) { x *= 2; });
        print("for_each        ", v);   // 2 4 6 8 10
    }
}

void foreachn()
{
    // ------------------------------------------------------------
    // std::for_each_n  -  jak for_each, ale przetwarza dokładnie
    // N elementów zaczynając od podanego iteratora (nie cały zakres)
    // ------------------------------------------------------------
    {
        std::vector<int> v {1, 2, 3, 4, 5};
        std::for_each_n(v.begin(), 3, [](int& x) { x *= 10; });
        print("for_each_n (n=3)", v);   // 10 20 30 4 5
    }
}

void inclusiveScan()
{
    // ------------------------------------------------------------
    // std::inclusive_scan  -  suma "narastająca" (prefix sum),
    // element i-ty WŁĄCZA i-ty element wejściowy
    // wejście:  1  2  3  4
    // wyjście:  1  3  6  10
    // ------------------------------------------------------------
    {
        std::vector<int> in {1, 2, 3, 4};
        std::vector<int> out(in.size());
        std::inclusive_scan(in.begin(), in.end(), out.begin());
        print("inclusive_scan  ", out);   // 1 3 6 10
    }
}

void exclusiveScan()
{
    // ------------------------------------------------------------
    // std::exclusive_scan  -  jak inclusive_scan, ale element i-ty
    // NIE zawiera i-tego elementu wejściowego (przesunięcie o 1),
    // wymaga wartości początkowej
    // wejście:  1  2  3  4   (init = 0)
    // wyjście:  0  1  3  6
    // ------------------------------------------------------------
    {
        std::vector<int> in {1, 2, 3, 4};
        std::vector<int> out(in.size());
        std::exclusive_scan(in.begin(), in.end(), out.begin(), 0);
        print("exclusive_scan  ", out);   // 0 1 3 6
    }
}

void transformInclusiveScan()
{
    // ------------------------------------------------------------
    // std::transform_inclusive_scan  -  najpierw transformuje każdy
    // element (UnaryOp), potem liczy sumę narastającą (BinaryOp)
    // np. transformacja x*x, potem suma narastająca
    // wejście:  1  2  3  4  ->  po x*x: 1 4 9 16
    // wyjście:  1  5  14  30
    // ------------------------------------------------------------
    {
        std::vector<int> in {1, 2, 3, 4};
        std::vector<int> out(in.size());
        std::transform_inclusive_scan(in.begin(), in.end(), out.begin(),
            std::plus<>(),                     // BinaryOp (suma)
            [](int x) { return x * x; });       // UnaryOp (transformacja)
        print("transform_incl. ", out);   // 1 5 14 30
    }
}

void transformExclusiveScan()
{
    // ------------------------------------------------------------
    // std::transform_exclusive_scan  -  jak wyżej, ale wykluczająco
    // (przesunięcie o 1), wymaga wartości początkowej
    // wejście po x*x: 1 4 9 16   (init = 0)
    // wyjście:  0  1  5  14
    // ------------------------------------------------------------
    {
        std::vector<int> in {1, 2, 3, 4};
        std::vector<int> out(in.size());
        std::transform_exclusive_scan(in.begin(), in.end(), out.begin(), 0, std::plus<>(), [](int x) { return x * x; });
        print("transform_excl. ", out);   // 0 1 5 14
    }
}

void reduce()
{
    // ------------------------------------------------------------
    // std::reduce  -  jak std::accumulate, ale KOLEJNOŚĆ łączenia
    // elementów jest NIEOKREŚLONA (nawet bez execution policy!) -
    // pozwala to na równoległość/wektoryzację. Wymaga, by BinaryOp
    // był (w ideale) łączny i przemienny.
    //
    // Tu użyty jako BinaryOp lambda sklejająca stringi ":" - operacja
    // NIE jest przemienna, więc kolejność wyniku może się różnić
    // między uruchomieniami - przykład czysto demonstracyjny.
    // ------------------------------------------------------------
    {
        std::vector<std::string> words {"ala", "ma", "kota"};

        auto join = [](auto fir, auto sec) { return fir + ":" + sec; };

        std::string result = std::reduce(std::execution::seq,           // deterministyczna kolejność w praktyce dla seq
            words.begin(), words.end(),std::string(""),               // wartość początkowa
            join);

        std::cout << "reduce (string) : " << result << "\n";
        // np. ":ala:ma:kota"  (kolejność sklejania nie jest gwarantowana przez standard)
    }
}

void transformReduce()
{
    // ------------------------------------------------------------
    // std::transform_reduce  -  najpierw transformuje elementy
    // (UnaryOp), potem redukuje je do jednej wartości (BinaryOp),
    // tak jak reduce - kolejność nieokreślona
    //
    // Tu: transformacja - dodanie prefiksu do każdego słowa,
    // potem sklejenie ich tą samą lambdą co wyżej
    // ------------------------------------------------------------
    {
        std::vector<std::string> words {"ala", "ma", "kota"};

        auto join = [](auto fir, auto sec) { return fir + ":" + sec; };
        auto prefix = [](const std::string& s) { return "#" + s; };

        std::string result = std::transform_reduce(
            std::execution::seq,
            words.begin(), words.end(),
            std::string(""),   // wartość początkowa
            join,               // BinaryOp - redukcja
            prefix);            // UnaryOp - transformacja

        std::cout << "transform_reduce: " << result << "\n";
        // np. ":#ala:#ma:#kota"
    }
}

int main()
{
    foreach();
    foreachn();
    exclusiveScan();
    transformInclusiveScan();
    transformExclusiveScan();
    reduce();
    transformReduce();
    return 0;
}