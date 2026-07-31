// Demonstracja koncepcji std::three_way_comparable (C++20, <compare>)
// Kompilacja: g++ -std=c++20 three_way_comparable_demo.cpp -o demo

#include <compare>
#include <iostream>
#include <string>
#include <limits>

// ------------------------------------------------------------
// Point - operator<=> = default generuje strong_ordering
// (bo int ma silny porzadek, wiec kompilator dobiera
// najsilniejsza mozliwa kategorie dla typow skladowych)
// ------------------------------------------------------------
struct Point
{
    int x, y;
    auto operator<=>(const Point&) const = default;
};

// ------------------------------------------------------------
// Money - wlasny operator<=> zwracajacy jawnie weak_ordering
// (dwie kwoty moga byc "rownowazne" logicznie, mimo ze
// przechowuja inne dane wewnetrznie - tutaj upraszczamy
// przez porownanie tylko wartosci w groszach)
// ------------------------------------------------------------
struct Money
{
    long grosze;
    std::weak_ordering operator<=>(const Money& other) const
    {
        return grosze <=> other.grosze;
    }
};

// ------------------------------------------------------------
// Measurement - typ oparty na double, wiec z natury wspiera
// tylko porzadek CZESCIOWY (partial_ordering) - przez NaN
// ------------------------------------------------------------
struct Measurement
{
    double value;
    std::partial_ordering operator<=>(const Measurement& other) const
    {
        return value <=> other.value;
    }
};

// ------------------------------------------------------------
// NotComparable - celowo NIE ma operatora<=>
// ------------------------------------------------------------
struct NotComparable
{
    int data;
};

template<typename T, typename Cat = std::partial_ordering>
void report(const char* name)
{
    std::cout << name << " three_way_comparable: " << std::boolalpha << std::three_way_comparable<T, Cat> << std::endl;
}

int main()
{
    // --- Sprawdzenie konceptu dla typow wbudowanych i wlasnych ---
    report<int>("int         ");                                   // true
    report<double>("double      ");                                 // true (partial - NaN)
    report<std::string>("string      ");                            // true

    report<Point>("Point       ");                                  // true, strong_ordering
    report<Point, std::strong_ordering>("Point (strong)");           // true

    report<Money>("Money       ");                                  // true (partial - domyslne Cat)
    report<Money, std::weak_ordering>("Money  (weak)  ");            // true

    report<Measurement>("Measurement ");                             // true, tylko partial_ordering
    report<Measurement, std::strong_ordering>("Measurement(strong)"); // false! partial nie spelnia strong

    report<NotComparable>("NotComparable");                          // false - brak operatora<=>

    std::cout << "\n--- Realne uzycie operatora <=> ---\n";

    Point p1{1, 2}, p2{1, 3};
    auto cmp = p1 <=> p2;
    if (cmp < 0)       std::cout << "p1 < p2\n";
    else if (cmp > 0)  std::cout << "p1 > p2\n";
    else               std::cout << "p1 == p2\n";

    Measurement m1{1.0}, m2{std::numeric_limits<double>::quiet_NaN()};
    auto mcmp = m1 <=> m2;
    if (mcmp == std::partial_ordering::unordered)
        std::cout << "m1 i m2 sa nieporownywalne (NaN)\n";

    return 0;
}