# Laboratorium – Klient–Serwer z użyciem kolejek komunikatów POSIX

## Ćwiczenie 8 – Klient–Serwer: Kolejki komunikatów

Autor: Jan Bajor
Data: 18.05.2025
Miejsce: Kraków

Folder zawiera 5 kodów realizujących problem serwer-klient.
Kody mqhelper.h i .c zawierają odpowiednio deklaracje i implementacje funkcji używanych do obsługi kolejek.

Serwer odbiera zapytanie od klientów w postaci operacji arytmetycznej i zwraca je klientowi, wypisując przy okazji kolejkę tego klienta.
Klient również wewnątrz odblicza zadaną operację w celu sprawdzenia poprawności.

Aby uruchomić program należy użyć komendy make run-cw8.
Liczba klientów i losowy czas spania są podawane jako argumenty wejścia programu i są zmiennymi w makefile.

### Cel

Zapoznanie się z komunikacją międzyprocesową przy użyciu **kolejek komunikatów POSIX** poprzez implementację architektury **Klient–Serwer**.

---

# Zadanie

Zaimplementuj system typu **Klient–Serwer**, w którym:

- klient wysyła do serwera żądanie wykonania działania arytmetycznego,
- serwer wykonuje obliczenie,
- serwer odsyła wynik do klienta,
- klient odbiera wynik i wyświetla go na ekranie.

Obsługiwane działania:

```text
liczba operator liczba
```

gdzie:

```text
operator ∈ {+, -, *, /}
```

Przykład:

```text
2+3
```

Serwer powinien umożliwiać jednoczesną obsługę wielu klientów.

---

# Serwer

## Tworzenie kolejki serwera

Serwer powinien:

1. Utworzyć kolejkę komunikatów POSIX w trybie odbierania.
2. Nazwa kolejki powinna być zdefiniowana we wspólnym pliku nagłówkowym.
3. Plik nagłówkowy powinien być dołączony zarówno w programie klienta, jak i serwera.

Przykład:

```c
#define SERVER_QUEUE "/server_queue"
```

---

## Działanie serwera

Serwer powinien działać w nieskończonej pętli jako proces typu **demon**:

1. Oczekuje na komunikaty w swojej kolejce.
2. Po otrzymaniu komunikatu:
   - odczytuje PID klienta,
   - otwiera kolejkę klienta w trybie wysyłania,
   - odczytuje działanie arytmetyczne,
   - wykonuje obliczenie,
   - wysyła wynik do klienta.

---

## Format komunikatu

Komunikat wysyłany przez klienta powinien zawierać:

```text
PID klienta + działanie arytmetyczne
```

Przykład:

```text
17895 2+3
```

Do przygotowania komunikatu można użyć:

```c
snprintf()
```

Do odczytu danych:

```c
atoi()
sscanf()
```

---

## Kończenie pracy serwera

Serwer powinien kończyć działanie po otrzymaniu sygnału:

```text
SIGINT
```

(np. po użyciu):

```text
Ctrl + C
```

Obsługa sygnału powinna:

- zamknąć kolejkę serwera,
- usunąć kolejkę komunikatów.

Usuwanie zasobów należy umieścić:

- w funkcji zarejestrowanej przez `atexit()`,
- w funkcji obsługi sygnału `SIGINT`.

---

# Klient

## Tworzenie kolejki klienta

Każdy klient powinien:

1. Utworzyć własną kolejkę komunikatów do odbierania.
2. Nazwa kolejki powinna mieć format:

```text
/PID
```

gdzie:

- `PID` oznacza identyfikator procesu klienta.

Przykład:

```text
/17895
```

Do tworzenia nazwy można użyć:

```c
snprintf()
```

---

## Działanie klienta

Klient powinien:

1. Otworzyć kolejkę serwera w trybie wysyłania.
2. W pętli:
   - pobierać działanie z klawiatury,
   - tworzyć komunikat zawierający:
     - własny PID,
     - wyrażenie arytmetyczne,
   - wysyłać komunikat do serwera,
   - odbierać wynik z własnej kolejki,
   - wyświetlać wynik.

Do pobierania danych z klawiatury można użyć:

```c
fgets()
```

---

## Kończenie pracy klienta

Pętlę klienta można zakończyć poprzez EOF:

```text
Ctrl + D
```

Po zakończeniu klient powinien:

- zamknąć własną kolejkę,
- usunąć własną kolejkę,
- zamknąć kolejkę serwera.

Czynności te należy umieścić:

- w funkcji zarejestrowanej przez `atexit()`,
- w funkcji obsługi sygnału `SIGINT`.

---

# Testowanie wielu klientów

Procesy klienta i serwera należy uruchamiać w osobnych terminalach.

Można wykorzystać polecenie:

```bash
xterm -hold -title SERWER -bg red -fg black -e ./serwer.x &
```

Uruchomienie klientów:

```bash
xterm -hold -title KLIENT1 -bg green -fg black -e ./klient.x &
xterm -hold -title KLIENT2 -bg green -fg black -e ./klient.x &
```

Przykładowe polecenia należy umieścić w pliku:

```text
Makefile
```

---

# Komunikaty diagnostyczne

Procesy klienta i serwera powinny wypisywać informacje dotyczące działania programu.

W szczególności należy wyświetlać:

- utworzenie kolejki,
- nazwę kolejki,
- parametry kolejki komunikatów zaraz po utworzeniu.

---

# Biblioteka obsługi kolejek komunikatów

Należy stworzyć własną bibliotekę funkcji obsługujących kolejki komunikatów.

Biblioteka powinna zawierać funkcje będące nakładkami (**wrapperami**) na funkcje systemowe.

Powinna umożliwiać:

- tworzenie kolejki,
- otwieranie kolejki,
- wysyłanie komunikatów,
- odbieranie komunikatów,
- zamykanie kolejki,
- usuwanie kolejki.

---

## Obsługa błędów

Biblioteka powinna:

- zawierać diagnostykę błędów,
- wykorzystywać np. `perror()`,
- zwracać:

```text
0 – w przypadku błędu
```

Wywołania funkcji należy wykonywać poprzez makro:

```c
CheckError
```
