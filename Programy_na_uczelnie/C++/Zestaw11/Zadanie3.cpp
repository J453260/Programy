#include <concepts>
#include <iostream>

// ------------------------------------------------------------
// NotCopyable - typ z usuniętym konstruktorem kopiującym.
//
// UWAGA: usunięcie konstruktora kopiującego powoduje też,
// że kompilator NIE generuje niejawnie konstruktora
// przenoszącego (bo user-declared copy ctor blokuje jego
// automatyczne wygenerowanie). W efekcie NotCopyable nie
// spełnia ani copy_constructible, ani movable - a więc tym
// bardziej nie spełnia std::copyable (który wymaga obu).
// ------------------------------------------------------------

struct NotCopyable
{
    NotCopyable()=default;
    NotCopyable(const NotCopyable&) = delete;
};

template<typename T>
struct MyVector
{
    void push_back(const T&)requires std::copyable<T>{}
};

int main()
{
    // --- Sprawdzenie konceptu wprost, bez tworzenia obiektów ---
    std::cout << std::boolalpha;
    std::cout << "int         copyable: " << std::copyable<int>         << std::endl; // true
    std::cout << "NotCopyable copyable: " << std::copyable<NotCopyable> << std::endl; // false

    // --- Użycie z typem spełniającym koncept - kompiluje się ---
    MyVector<int>myVec1;
    myVec1.push_back(2020);

    // --- Użycie z typem NIE spełniającym koncept ---
    // Odkomentowanie poniższych dwóch linii spowoduje BŁĄD KOMPILACJI:
    //
    //   error: no matching member function for call to 'push_back'
    //   note: candidate template ignored: constraints not satisfied
    //   note: because 'std::copyable<NotCopyable>' evaluated to false

    //MyVector<NotCopyable>myVec2;
    //myVec2.push_back(NotCopyable()); //ERROR because not copyable

    return 0;
}
