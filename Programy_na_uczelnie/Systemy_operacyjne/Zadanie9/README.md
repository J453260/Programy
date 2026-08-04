# Laboratorium – Synchronizacja wątków

# Ćwiczenie 9 – Wzajemne wykluczanie dla wątków: muteksy

Autor: Jan Bajor
Data: 25.05.2025
Miejsce: Kraków

Folder zawiera 1 kod realizujący wzajemne wykluczanie dla wątków standardu POSIX z użyciem muteksów.
Najpierw mutex zostaje zainicjalizowany. Potem w pętli wątki są tworzone i dla każdego wątku jest uruchamiana funkcja "watek_funkcja".
W niej każdy wątek przechodzi przez sekcje prywatną i sekcję krytyczną inkrementując licznik.

Po zakończeniu pierwszej pętli druga pętla czeka na zakończenie wszystkich wątków, po czym następuje usunięcie mutexa, zwolnienie pamięci i zakonczenie programu.

## Cel

Zapoznanie się z mechanizmem wzajemnego wykluczania wątków przy użyciu **muteksów**.

---

## Zadanie

Przy pomocy muteksów zaimplementuj zadanie wzajemnego wykluczania dla wątków.

Do demonstracji działania programu można wykorzystać sekwencje sterujące konsoli (np. przykład `witaj.c` znajdujący się w katalogu **StartSO**).

---

## Demonstracja działania wątków

Każdy wątek powinien wykonywać cyklicznie:

1. Sekcję prywatną.
2. Sekcję krytyczną.

### Sekcja prywatna

Podczas wykonywania sekcji prywatnej wątek powinien:

- wypisywać odpowiedni komunikat po lewej stronie okna konsoli.

### Sekcja krytyczna

Podczas wykonywania sekcji krytycznej wątek powinien:

- wypisywać informację po prawej stronie okna konsoli,
- wykonywać operacje na wspólnym zasobie.

Każdy wątek może kilkukrotnie powtarzać cały cykl.

---

## Wymagania dotyczące synchronizacji

Przy poprawnie zaimplementowanym wzajemnym wykluczaniu:

- po prawej stronie terminala w danym momencie może znajdować się najwyżej jeden wątek,
- pozostałe wątki powinny znajdować się po lewej stronie,
- każdy wątek powinien posiadać ustalony wiersz terminala.

---

## Wspólny zasób

Do demonstracji dostępu do zasobu współdzielonego użyj np.:

- globalnej zmiennej licznikowej.

Zmiennej należy nadać początkową wartość:

```text
0
```

---

## Operacje w sekcji krytycznej

Każdy wątek powinien:

1. Na początku sekcji krytycznej:
   - przypisać wartość wspólnego licznika do własnego prywatnego licznika.

2. Następnie:
   - zwiększyć prywatny licznik o `1`.

3. Po pewnym czasie:
   - użyć np. `sleep()`,
   - przypisać wartość prywatnego licznika do wspólnego licznika.

---

## Sprawdzenie poprawności

Po zakończeniu działania wszystkich wątków należy sprawdzić:

- czy końcowa wartość wspólnego licznika jest zgodna z oczekiwaną.

---

## Obsługa błędów

Do diagnostyki błędów funkcji związanych z:

- wątkami,
- muteksami,

należy używać funkcji:

```c
strerror()
```
