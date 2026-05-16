### 1. Szablon funkcji `integrate`

Zaimplementuj szablon funkcji `integrate`, która jako pierwszy argument przyjmuje dowolny funktor.  
Funkcja ma dokonywać całkowania numerycznego w podanym zakresie.

```cpp
std::cout << ::integrate(sina(0), 0, 3.1415926, 0.01) << std::endl;
std::cout << ::integrate(sina(1), 0, 3.1415926, 0.01) << std::endl;
std::cout << ::integrate(sina(2), 0, 3.1415926, 0.01) << std::endl;
```

---

### 2. Funktory `Variable` i `Constant`

Stwórz odpowiednie funktory `Variable` oraz `Constant`, które mogą być używane jako argumenty funkcji `integrate`.

```cpp
Variable x;
integrate(x, 0, 1, 0.001);
integrate(Constant(1.0), 0, 1, 0.001);
```

---

### 3. Funktor `AddExpr` i operator `+`

Funktor `AddExpr` jest używany przez szablon operatora dodawania dwóch funktorów:

```cpp
template<typename LHS, typename RHS>
AddExpr<LHS, RHS> operator+(const LHS &l, const RHS &r)
```

Zwracany funktor może być podstawiony do funkcji całkującej.  
Dokonaj specjalizacji szablonu operatora `+` dla przypadku, w którym jeden z argumentów jest typu `double`:

```cpp
integrate(x + 1., 0, 1, 0.001);
```

---

### 4. `DivExpr`, `SinExpr` oraz operator `/`

Zaimplementuj szablony:
- `operator/(double l, const RHS &r)`
- `DivExpr`
- `sin` oraz `SinExpr`

Dokonaj całkowania następującej funkcji:

```cpp
integrate(1. / sin(x + 1.), 0, 1, 0.001);
```

---

### 5. Klasa opakowująca `Expr`

Operatory arytmetyczne nie będą mogły automatycznie wydedukować typu `T`:

```cpp
template<typename T, typename LHS, typename RHS>
Add<T, LHS, RHS> operator+(const LHS &l, const RHS &r)
```

ponieważ typ `T` nie pojawia się w argumentach wywołania.  
Zaimplementuj dodatkową klasę `Expr` opakowującą wyrażenia, która będzie przenosiła informację o typie.  
Przedstaw przykłady całkowania funkcji z użyciem zmiennej innego typu niż `double`.

---

### 6. Funktory dwóch zmiennych — `First` i `Second`

Zaimplementuj rozszerzenie klasy `Variable` dla przypadku funktorów dwóch zmiennych, tj. klas `First` oraz `Second`.  
Podaj przykład całkowania prostej funkcji, np.:

```cpp
// całkowanie funkcji x + y
```

---

### 7. Wektorowe szablony wyrażeń

Opisz sposób wykorzystania szablonów wyrażeń wektorowych (na podstawie przygotowanego wcześniej kodu) do efektywnego obliczenia wyrażeń wektorowych, np.:

```cpp
Vector v1(100, 1);
Vector v2(100, 2);
Vector res(100);
res = 1.2 * v1 + v1 * v2 + v2 * 0.5;
```
