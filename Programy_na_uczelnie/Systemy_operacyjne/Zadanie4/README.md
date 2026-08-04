# Laboratorium – Producent–Konsument z użyciem potoków nienazwanych

## Ćwiczenie 4 – Producent–Konsument: Potoki nienazwane

Autor: Jan Bajor
Data: 04.04.2025r.
Miejsce: Kraków

Folder zawiera 1 program - Cw4.c realizujący problem "Producent-Konsument".
Z pliku "Dane1.txt" producent pobiera dane, które później przekazuje do bufora.
Konsument pobiera dane z bufora i wpisuje je do pliku "Dane2.txt".
Nazwy plików z których są pobierane i wpisywane dane i przedział z którego są losowane liczby do funkcji sleep są podawane z linii komend.

Proces macierzysty, który jest producentem zczytuje w pętli z pliku dane i zapisuje je do bufora.
Później proces potomny, który jest konsumentem zczytuje dane z buforu, wypisuje je na ekran i przepisuje do pliku. Konsument również działa w pętli.
Funkcja rand() losuje liczby z podanego przedziału co odpowiada liczbom sekund na które program ma zostać uśpiony funkcją sleep(), co odpowiada symulacji różnych szybkości działania programu.

### Cel

Zapoznanie się z komunikacją międzyprocesową (IPC) przy użyciu potoków nienazwanych (`pipe()`) poprzez implementację klasycznego problemu **Producent–Konsument**.

---

## Zadanie

Przy pomocy potoków nienazwanych systemu UNIX zaimplementuj problem **Producenta i Konsumenta**.

### Producent

Proces Producenta powinien:

- pobierać dane (np. porcje bajtów) z pliku tekstowego,
- traktować odczytane dane jako „surowiec”,
- przesyłać je jako „towar” do potoku.

---

### Konsument

Proces Konsumenta powinien:

- odbierać dane z potoku,
- zapisywać je do innego pliku tekstowego.

> **Uwaga:** Rozmiary porcji danych odczytywanych i zapisywanych przez Producenta i Konsumenta nie muszą być jednakowe.

---

## Weryfikacja poprawności

Po zakończeniu działania programu (wyczerpaniu danych wejściowych):

- plik wejściowy,
- plik wyjściowy

powinny być **identyczne**.

Można to sprawdzić poleceniem:

```bash
diff -s plik_wejsciowy plik_wyjsciowy
```

Zaleca się umieszczenie tego polecenia w pliku **Makefile** po uruchomieniu programu.

---

## Komunikaty

Oba procesy powinny wypisywać na ekran odpowiednie informacje, w szczególności:

- wykonywaną operację,
- przesyłany „towar” (fragment danych).

---

## Symulacja różnych prędkości działania

Aby zasymulować różne szybkości pracy Producenta i Konsumenta:

- użyj funkcji `sleep()`,
- najlepiej z losowym czasem uśpienia.

---

## Wymagania

Do obsługi plików oraz komunikacji użyj wyłącznie funkcji systemowych:

- `read()`
- `write()`

Do komunikacji między procesami użyj:

- `pipe()`
```
