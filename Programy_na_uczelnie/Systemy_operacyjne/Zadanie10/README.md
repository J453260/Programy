# Laboratorium – Synchronizacja wątków

# Ćwiczenie 10 – Algorytm piekarni: P-wątki

Autor: Jan Bajor

Data: 02.06.2025

Miejsce: Kraków

Folder zawiera 1 kod: Cw10.c, zawierający implementacje algorytmu piekarni wraz ze wzajemnym wykluczaniem wątków standardu POSIX.
W funkcji "funkcja_watek" każdy wątek przechodzi przez sekcje prywatną i sekcję krytyczną inkrementując licznik, ale wewnątrz funkcji jest algorytm piekarni,
który zapewnia to, że do sekcji krytycznej wejdzie tylko jeden wątek.

Argumenty wejścia programu są zmiennymi w Makefile.

## Cel

Zapoznanie się z implementacją algorytmu wzajemnego wykluczania **algorytmu piekarni (Bakery Algorithm)** dla wątków.

---

## Zadanie

Przy pomocy **P-wątków (`pthread`)** zaimplementuj algorytm piekarni przedstawiony w wykładzie 5 z przedmiotu **Systemy Operacyjne**.

---

## Wymagania

Program powinien:

- tworzyć wiele wątków,
- implementować algorytm piekarni do synchronizacji dostępu,
- zapewniać wzajemne wykluczanie podczas wykonywania sekcji krytycznej.

---

## Demonstracja działania

Poprawność działania programu należy zademonstrować analogicznie jak w Ćwiczeniu 9:

- wątki powinny wykonywać sekcje prywatne i krytyczne,
- należy pokazać, że w sekcji krytycznej w danym momencie znajduje się tylko jeden wątek,
- należy wykorzystać komunikaty wypisywane na ekranie.

---

## Sprawdzenie poprawności

Należy sprawdzić, czy:

- algorytm zapewnia wzajemne wykluczanie,
- wspólny zasób jest modyfikowany poprawnie,
- końcowy wynik operacji wykonywanych przez wszystkie wątki jest zgodny z oczekiwaniami.
