# Laboratorium – Producent–Konsument z użyciem potoków nazwanych

## Ćwiczenie 5 – Producent–Konsument: Potoki nazwane (FIFO)

Autor: Jan Bajor
Data: 13.04.2025
Miejsce: Kraków

Katalog zawiera 3 kody: 5a Producent i Konsument

Producent i konsument są uruchamiane z kodu 5a.
Po uruchomieniu programu 5a zostaną otwarte 2 okna realizujące problem "Producenta i konsumenta" z ćwiczenia 4.

Program do uruchomienia potrzebuje następujących argumentów wywołania programu:
2 pliki tekstowe: z pierwszego zapisuje dane, które są później przepisywane do drugiego
Przedział z którego są losowane 2 liczby symulujące czas pracy
Rozmiar buforu producenta i konsumenta (mogą to być różne liczby)
Skompilowane pliki producenta i konsumenta.

Argumenty wywołania programu są wpisywane w następującej strukturze:
./5a, Pierwszy plik tekstowy, Drugi plik tekstowy, Dolna granica przedziału, Górna granica przedziału, Rozmiar buforu producenta, Rozmiar buforu konsumenta, ./Producent, ./Konsument

### Cel

Zapoznanie się z komunikacją międzyprocesową (IPC) przy użyciu **potoków nazwanych (FIFO)** poprzez implementację problemu **Producent–Konsument**.

---

## Zadanie

Przy pomocy potoków nazwanych systemu UNIX zaimplementuj problem **Producenta i Konsumenta** z **Ćwiczenia 4**.

---

## Zadanie a) Tworzenie potoku FIFO w programie

Utwórz potok FIFO z poziomu programu.

Następnie uruchom procesy Producenta i Konsumenta:

- w procesie macierzystym i potomnym,
- **lub**
- w dwóch procesach potomnych.

### Wymagania

- Potok FIFO powinien zostać utworzony przez program.
- Po zakończeniu działania programu potok powinien zostać usunięty.
- Usuwanie potoku należy zrealizować w funkcji zarejestrowanej przy pomocy `atexit()`.

---

## Zadanie b) Komunikacja między niezależnymi procesami

Sprawdź, że potoki FIFO umożliwiają komunikację pomiędzy **niezależnie uruchamianymi procesami**.

### Wymagania

1. Utwórz potok FIFO z poziomu wiersza poleceń.
2. Uruchom proces Producenta oraz Konsumenta niezależnie z poziomu powłoki, np. w dwóch różnych terminalach.

Można wykorzystać polecenie:

```bash
xterm -hold -title "nazwa okna" -e nazwa_programu &
```

dla każdego z procesów.

---

## Makefile

Zaleca się umieszczenie w pliku **Makefile** poleceń:

- tworzących potok FIFO,
- uruchamiających Producenta,
- uruchamiających Konsumenta,
- usuwających potok FIFO po zakończeniu działania programu.
