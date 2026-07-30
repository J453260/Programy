# Szablony wyrażeń (Expression Templates)

Technika C++ pozwalająca efektywnie obliczać wyrażenia wektorowe, np.:

```cpp
Vector v1(100, 1);
Vector v2(100, 2);
Vector res(100);
res = 1.2 * v1 + v1 * v2 + v2 * 0.5;
```

## Problem

Przy zwykłych przeciążonych operatorach każde `+` i `*` tworzy **osobny, tymczasowy wektor**:

```cpp
Vector t1 = 1.2*v1;   // alokacja + pętla
Vector t2 = v1*v2;    // alokacja + pętla
Vector t3 = t1+t2;    // alokacja + pętla
Vector t4 = v2*0.5;   // alokacja + pętla
res = t3+t4;          // alokacja + pętla
```

5 zbędnych alokacji i 5 przejść po danych zamiast jednego — dla dużych wektorów to poważny koszt wydajnościowy.

## Rozwiązanie

Operatory **nie liczą wyniku od razu** — zwracają mały obiekt reprezentujący **wyrażenie** (z referencjami do argumentów), a właściwe obliczenie odkłada się do momentu przypisania:

```cpp
template<typename E1, typename E2>
struct VecSum
{
    const E1& u;
    const E2& v;
    double operator[](size_t i) const { return u[i] + v[i]; }  // liczy się dopiero tu
};

template<typename E1, typename E2>
VecSum<E1,E2> operator+(const E1& u, const E2& v) { return {u, v}; }
```

Wyrażenie `1.2*v1 + v1*v2 + v2*0.5` buduje więc tylko **zagnieżdżony typ** (drzewo referencji), nic nie licząc. Dopiero przypisanie:

```cpp
Vector& operator=(const auto& expr)
{
    for (size_t i = 0; i < size(); ++i)
        _data[i] = expr[i];   // JEDNA pętla dla całego wyrażenia
}
```

powoduje, że `expr[i]` rekurencyjnie rozwija się do jednego wyrażenia arytmetycznego, a kompilator inlineuje wszystko w **jedną pętlę** — tak, jakby ktoś ręcznie napisał:

```cpp
for (size_t i = 0; i < 100; i++)
    res[i] = 1.2*v1[i] + v1[i]*v2[i] + v2[i]*0.5;
```

## Kluczowe elementy techniki

- **CRTP** (*Curiously Recurring Template Pattern*) zamiast wirtualnych metod — statyczny polimorfizm, zero narzutu `vtable`.
- **Referencje, nie kopie** w węzłach wyrażeń.
- **Leniwa ewaluacja (lazy evaluation)** — liczenie dopiero przy `operator=`.

## Efekt

Naturalna, matematyczna składnia + wydajność ręcznie napisanej pętli, zero tymczasowych obiektów pośrednich.

Tak działają biblioteki takie jak **Eigen**, **Blitz++**, **Armadillo**, **Blaze**.

## Ryzyko

Wiszące referencje (*dangling references*) przy nieostrożnym użyciu, np.:

```cpp
auto expr = 1.2 * v1;   // expr trzyma referencję do v1
// jeśli v1 przestanie istnieć zanim expr zostanie użyte -> UB
```
