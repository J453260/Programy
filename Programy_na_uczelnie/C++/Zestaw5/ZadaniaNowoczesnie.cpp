#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
#include <algorithm>

class Klasa {};

// =================================================================
// ZADANIE 1: is_class<T>
// =================================================================
// W C++11+ mamy to w bibliotece standardowej.
template <typename T>
constexpr bool is_class_v = std::is_class_v<Klasa>;


// =================================================================
// ZADANIE 2: has_value_type<T>
// =================================================================
// W C++20 używamy Konceptów (Concepts) - najbardziej czytelna metoda.
template <typename T>
concept HasValueType = requires {
    typename T::value_type;
};


// =================================================================
// ZADANIE 3: Is_convertible<T, U>
// =================================================================
// Gotowiec z biblioteki standardowej.
template <typename From, typename To>
constexpr bool is_convertible_v = std::is_convertible_v<From, To>;


// =================================================================
// ZADANIE 4: Strip<T>
// =================================================================
// Od C++20 mamy std::remove_cvref_t, który robi dokładnie to, o co pyta zadanie.
template <typename T>
using Strip_t = std::remove_cvref_t<T>;


// =================================================================
// ZADANIE 5: Promote i operator+ dla wektorów
// =================================================================
// std::common_type wyznacza wspólny typ dla dowolnej liczby typów, 
// uwzględniając standardowe zasady promocji języka C++.
template <typename T, typename U>
auto operator+(const std::vector<T>& a, const std::vector<U>& b) {
    using ResultType = std::common_type_t<T, U>;
    std::vector<ResultType> result;
    result.reserve(a.size());

    // Używamy std::transform dla nowoczesnego sumowania
    std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(result),
                   [](const T& val1, const U& val2) {
                       return static_cast<ResultType>(val1) + static_cast<ResultType>(val2);
                   });
    return result;
}


// =================================================================
// ZADANIE 6: Listy typów (Type Lists)
// =================================================================
// Variadic Templates eliminują potrzebę Head/Tail i Null_type.
template <typename... Ts>
struct TypeList {
    // 6.1 Długość listy
    static constexpr std::size_t length = sizeof...(Ts);

    // 6.2 Typ pod indeksem (wykorzystujemy std::tuple_element)
    template <std::size_t I>
    using At = typename std::tuple_element_t<I, std::tuple<Ts...>>;

    // 6.3 Czy zawiera typ (wykorzystujemy Fold Expressions z C++17)
    template <typename U>
    static constexpr bool contains = (std::is_same_v<U, Ts> || ...);
};


// =================================================================
// PREZENTACJA DZIAŁANIA
// =================================================================
int main() {
    std::cout << std::boolalpha;

    // Test 1 & 2
    std::cout << "Zad 1 (is_class int): " << is_class_v<int> << "\n";
    std::cout << "Zad 2 (vector has value_type): " << HasValueType<std::vector<int>> << "\n";

    // Test 4
    using MyType = Strip_t<const int&>;
    std::cout << "Zad 4 (Strip const int&): " << std::is_same_v<MyType, int> << "\n";

    // Test 5
    std::vector<int> v1 = {1, 2};
    std::vector<double> v2 = {0.5, 1.5};
    auto res = v1 + v2; // Wynik automatycznie będzie vector<double>
    std::cout << "Zad 5 (vector int + double): res[0] = " << res[0] << "\n";

    // Test 6
    using MyList = TypeList<int, double, std::string>;
    std::cout << "Zad 6 (Length): " << MyList::length << "\n";
    std::cout << "Zad 6 (Contains double): " << MyList::contains<double> << "\n";
    std::cout << "Zad 6 (Contains float): " << MyList::contains<float> << "\n";

    return 0;
}
