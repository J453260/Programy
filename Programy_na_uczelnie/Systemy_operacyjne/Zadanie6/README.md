# Laboratorium – Wzajemne wykluczanie procesów z użyciem semaforów POSIX

## Ćwiczenie 6 – Wzajemne wykluczanie dla procesów: semafory

Autor: Jan Bajor
Data: 24.04.2025
Miejsce: Kraków

Program realizuje problem wzajemnego wykluczania procesów używając semaforów.
Program tworzy w pętli n procesów a następnie wysyła je do sekcji krytycznej. N jest podawane jako argument wejścia programu.
W sekcji krytycznej jest otwierany plik z którego jest pobierana liczba a następnie inkrementowana.
Ostatecznie liczba powinna być zinkrementowana o n.
Jeżeli jeden proces wejdzie do sekcji krytycznej to semafor blokuje tę możliwość innemu, aż do czasu odblokowania przez proces, który wszedł.

Program wymaga argumentów wejścia, które należy wpisywać w następującej strukturze:
./Cw6, Nazwa pliku, Dolna granica przedziału, Górna granica przedziału, Nazwa semafora, ./Sekcja_krytyczna, n procesów.

### Cel

Zapoznanie się z mechanizmem wzajemnego wykluczania procesów przy użyciu **nazwanych semaforów POSIX**.

---

## Zadanie

Przy pomocy nazwanych semaforów POSIX zaimplementuj zadanie wzajemnego wykluczania procesów zgodnie z pseudokodem przedstawionym na końcu podrozdziału **5.1**.

### Wymagania

- Czas wykonywania operacji na wspólnym zasobie zasymuluj przy pomocy funkcji `sleep()`.
- W celu pokazania poprawności działania programu wypisuj komunikaty:
  - przed wejściem do sekcji krytycznej,
  - podczas wykonywania sekcji krytycznej,
  - po opuszczeniu sekcji krytycznej.
- Wyświetlaj również aktualną wartość semafora.
- Bezpośrednio po utworzeniu semafora zainicjuj go odpowiednią wartością.

---

## Biblioteka do obsługi semaforów

Stwórz własną bibliotekę zawierającą proste funkcje do obsługi semaforów.

Biblioteka powinna udostępniać funkcje do:

- tworzenia semafora,
- otwierania semafora,
- odczytywania wartości semafora,
- wykonywania operacji na semaforze,
- zamykania semafora,
- usuwania semafora.

### Wymagania

Funkcje powinny korzystać z odpowiednich funkcji systemowych/bibliotecznych oraz zawierać obsługę błędów (np. z wykorzystaniem `perror()`).

#### Funkcje tworzące i otwierające semafor

Powinny zwracać:

- adres semafora w przypadku sukcesu,
- `NULL` w przypadku błędu.

#### Pozostałe funkcje

Powinny zwracać:

- `1` w przypadku sukcesu,
- `0` w przypadku błędu.

Wszystkie funkcje należy wywoływać jako argument makra **`CheckError`** opisanego w materiałach.

---

## Program powielający procesy

Napisz program odpowiedzialny za tworzenie procesów realizujących wzajemne wykluczanie.

Program powinien wykorzystywać funkcje:

- `fork()`
- `execlp()`

### Argumenty programu

Program powinien przyjmować jako argumenty:

- nazwę programu uruchamianego przez `execlp()`,
- liczbę tworzonych procesów,
- liczbę sekcji krytycznych/prywatnych wykonywanych przez każdy proces.

### Działanie programu

Program powinien:

1. utworzyć semafor,
2. zainicjować go odpowiednią wartością,
3. uruchomić wymagane procesy,
4. poczekać na zakończenie wszystkich procesów potomnych,
5. usunąć semafor.

---

## Usuwanie semafora

Semafor powinien być usuwany:

- w funkcji zarejestrowanej przez `atexit()`,
- oraz w przypadku otrzymania sygnału `SIGINT`.

### Obsługa sygnału SIGINT

Na wypadek przerwania programu kombinacją **Ctrl+C**:

- zarejestruj funkcję obsługi sygnału przy pomocy `signal()`,
- w funkcji obsługi wywołaj:

```c
exit(EXIT_SUCCESS);
```

> Zwróć uwagę na różnicę pomiędzy funkcjami `exit()` i `_exit()` oraz na sytuacje, w których należy ich używać.

---

## Weryfikacja poprawności działania

Program powielający powinien na początku:

1. utworzyć plik tekstowy `numer.txt`,
2. zapisać do niego liczbę:

```text
0
```

Każdy proces realizujący wzajemne wykluczanie powinien w swojej sekcji krytycznej:

1. odczytać liczbę z pliku,
2. zwiększyć ją o `1`,
3. odczekać losowy czas (np. przy pomocy `rand()`),
4. zapisać nową wartość do pliku.

Po zakończeniu działania wszystkich procesów program powielający powinien:

- odczytać końcową wartość z pliku,
- sprawdzić jej poprawność,
- wypisać odpowiedni komunikat.

---

## Pytanie

**Sprawdź, jaka będzie końcowa wartość liczby zapisanej w pliku, jeśli program zostanie uruchomiony bez użycia sekcji krytycznej.**
