# Laboratorium – Producent–Konsument z użyciem pamięci dzielonej i semaforów POSIX

## Ćwiczenie 7 – Producent–Konsument: pamięć dzielona i semafory

Autor: Jan Bajor
Data: 02.05.2025
Miejsce: Kraków

Program zawiera 7 kodów realizujący problem producenta i konsumenta za pomocą semaforów i pamięci dzielonej.
Producent otwiera plik wejściowy i czyta z niego dane.
Dla każdego przeczytanego znaku, producent czeka, aż będzie możliwe wstawienie danych do bufora, wstawia dane do bufora w pozycji wskazanej przez zmienną, uaktualnia wskaźnik pozycji wstawiania, sygnalizuje konsumentowi, że nowy element jest dostępny do odczytu.

Dla każdego elementu w buforze konsument czeka, aż producent wstawi dane do bufora, odczytuje dane z bufora w pozycji wskazanej przez zmienną, uaktualnia wskaźnik pozycji wyjmowania, sygnalizuje producentowi, że miejsce w buforze zostało zwolnione i może tam wstawić kolejny element.

### Cel

Zapoznanie się z komunikacją międzyprocesową przy użyciu:

- pamięci dzielonej,
- nazwanych semaforów POSIX,

poprzez implementację problemu **Producent–Konsument**.

---

## Zadanie

Przy pomocy pamięci dzielonej oraz semaforów POSIX zaimplementuj problem **Producenta i Konsumenta** z Ćwiczenia 4.

Zamiast potoku należy wykorzystać:

- **N-elementowy bufor cykliczny**,
- umieszczony w pamięci dzielonej.

Bufor powinien działać w sposób cykliczny:

- po dojściu do końca bufora następuje powrót na jego początek.

---

## Bufor cykliczny

Elementem bufora powinna być ustalona porcja danych:

- większa niż 1 bajt.

Przykładowa definicja:

```c
#define NELE 20   // Rozmiar elementu bufora w bajtach
#define NBUF 5    // Liczba elementów bufora

typedef struct {
    char element[NELE];   // Jednostka towaru
} Towar;

typedef struct {
    Towar bufor[NBUF];    // Wspólny bufor danych
    int wstaw;            // Pozycja wstawiania danych
    int wyjmij;           // Pozycja pobierania danych
} SegmentPD;
```

---

## Pamięć dzielona

Obiekt bufora należy umieścić w pamięci dzielonej i odwzorować w przestrzeniach adresowych procesów Producenta i Konsumenta.

Przykład:

```c
SegmentPD *wpd = (SegmentPD *) mmap(
    NULL,
    sizeof(SegmentPD),
    PROT_READ | PROT_WRITE,
    MAP_SHARED,
    des,
    0
);
```

Po uzyskaniu wskaźnika można wykonywać operacje na wspólnym segmencie:

```c
wpd->wyjmij = (wpd->wyjmij + 1) % NBUF;
```

---

## Synchronizacja

Dostęp do wspólnego bufora należy synchronizować przy pomocy:

- nazwanych semaforów POSIX.

Semafory powinny zabezpieczać:

- dostęp do wolnych miejsc w buforze,
- dostęp do zajętych elementów,
- wzajemne wykluczanie dostępu do bufora.

---

## Uruchamianie procesów

Procesy Producenta i Konsumenta należy uruchamiać:

1. W procesach potomnych utworzonych przez `fork()`.
2. Przy pomocy funkcji `execlp()`.

Proces macierzysty powinien:

1. Utworzyć i zainicjalizować:
   - semafory,
   - pamięć dzieloną.
2. Utworzyć procesy potomne.
3. Poczekać na zakończenie procesów potomnych.
4. Wykonać odpowiednie porządki.

---

## Usuwanie zasobów

Podobnie jak w Ćwiczeniu 6:

- usuwanie pamięci dzielonej,
- usuwanie semaforów,

należy umieścić:

- w funkcji zarejestrowanej przez `atexit()`,
- w funkcji obsługi sygnału `SIGINT`.

Obsługa `SIGINT` powinna umożliwiać poprawne zakończenie programu po użyciu kombinacji:

```text
Ctrl + C
```

---

# Biblioteka obsługi pamięci dzielonej

Należy stworzyć własną bibliotekę funkcji do obsługi pamięci dzielonej.

Biblioteka powinna zawierać funkcje do:

- tworzenia segmentu pamięci dzielonej,
- otwierania segmentu,
- odwzorowania pamięci,
- uzyskiwania dostępu do segmentu,
- zamykania segmentu,
- usuwania segmentu.

Funkcje powinny:

- korzystać z odpowiednich funkcji systemowych,
- posiadać diagnostykę błędów,
- wykorzystywać `perror()`.

Obsługę błędów należy realizować analogicznie jak dla semaforów.

Wywołania funkcji powinny być wykonywane poprzez makro:

```c
CheckError
```

---

# Biblioteki statyczne i dynamiczne

Z modułów obsługi:

- semaforów,
- pamięci dzielonej,

należy utworzyć:

## Bibliotekę statyczną

oraz

## Bibliotekę dynamiczną (współdzieloną)

ang. **dynamic/shared library**

Biblioteki należy umieścić w katalogu:

```text
./lib
```

---

## Uruchamianie programu z biblioteką dynamiczną

Program korzystający z biblioteki dynamicznej należy uruchamiać na dwa sposoby zgodnie z przykładem przedstawionym w materiale **StartSO**.

---

# Pytanie dodatkowe

Podaj w pseudokodzie uogólnienie synchronizacji dla problemu Producent–Konsument na przypadek:

- wielu producentów,
- wielu konsumentów.

Dla uproszczenia przyjmij:

- kolejność przesyłanych porcji danych nie ma znaczenia.
