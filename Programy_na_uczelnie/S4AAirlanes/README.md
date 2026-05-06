# S4A Airlines
# System zarządzania samolotami

---

## Opis

Projekt symuluje zarządzanie samolotami przypisanymi do tras w czasie.

Każdy samolot przechowuje historię zmian liczby pasażerów oraz swojego statusu (aktywny / wycofany).

Program umożliwia wykonywanie operacji modyfikujących stan samolotów oraz zapytań o łączną liczbę dostępnych miejsc w zadanym przedziale tras i czasu.

---

## Struktura projektu

Projekt składa się z dwóch głównych klas:

### `Samolot.java`

Reprezentuje pojedynczy samolot i jego historię zmian w czasie.

Odpowiada za:
- przechowywanie zmian liczby pasażerów
- obsługę operacji (`P`, `C`, `A`)
- obliczanie sumy pasażerów do danego dnia (`Q`)

---

### `Main.java`

Obsługuje:
- wczytywanie danych wejściowych
- przetwarzanie zapytań
- komunikację z obiektami `Samolot`

---

## Wymagania

- Java 21
- Maven 3.9.9
- Projekt budowany przez Apache Maven

---

## Jak uruchomić program

1. Budowanie projektu:

```bash
mvn clean package
```

2. Uruchomienie:
   
```bash
java -jar target/s4a-airlines-1.0.jar < input.txt
```

W pliku input.txt znajdują się dane wejściowe.

## Format wejścia

### Pierwsza linia:

n q


* `n` – liczba tras (samolotów)
* `q` – liczba zapytań

---

### Druga linia:

```
p1 p2 p3 ... pn
```

* początkowa liczba pasażerów dla każdego samolotu

---

### Kolejne `q` linii – zapytania:

#### 🔹 `P i p t`

Zmiana liczby pasażerów samolotu `i` na `p` od dnia `t`

#### 🔹 `C i t`

Wycofanie samolotu `i` od dnia `t`

#### 🔹 `A i p t`

Przypisanie nowego samolotu do trasy `i`
z liczbą pasażerów `p` od dnia `t`

#### 🔹 `Q i j t`

Oblicza sumę dostępnych miejsc:

* dla tras od `i` do `j`
* od dnia `1` do dnia `t`

---

## Przykład wejścia

```
3 4
100 200 150
P 1 120 5
C 2 10
A 2 180 15
Q 1 3 20
```

---

## Przykład wyjścia

```
8920
```

## Jak to działa

* Każdy samolot przechowuje tylko **momenty zmian** (zdarzenia)
* Zamiast zapisywać każdy dzień osobno, system operuje na **przedziałach czasu**
* Zapytanie `Q` oblicza sumę jako:

  > liczba pasażerów × liczba dni

dla każdego fragmentu historii

---

## Złożoność

* `P`, `C`, `A` → O(1)
* `Q` → O(n × liczba_zdarzeń)

---

## Uwagi

* Program zakłada poprawność danych wejściowych
* Indeksy tras zaczynają się od `1`
* Samolot może być wielokrotnie przypisywany i wycofywany

---

## Autor: Jan Bajor
