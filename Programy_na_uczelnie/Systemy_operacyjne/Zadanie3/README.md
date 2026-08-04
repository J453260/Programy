# Laboratorium – Obsługa sygnałów w systemie Linux

## Ćwiczenie 3 – Wysyłanie i obsługa sygnałów

### Cel

Zapoznanie się z mechanizmami obsługi sygnałów w systemie Linux, ich wysyłaniem do procesów oraz zarządzaniem grupami procesów.

---

## Zadanie a) Program do obsługi sygnałów

Napisz program umożliwiający trzy sposoby obsługi sygnału:

1. wykonanie operacji domyślnej,
2. ignorowanie sygnału,
3. przechwycenie sygnału i wykonanie własnej procedury obsługi.

### Wymagania

- Do oczekiwania na sygnał użyj funkcji `pause()`.
- Uruchom program i wysyłaj do niego sygnały:
  - za pomocą odpowiednich sekwencji klawiszy (np. `Ctrl+C`),
  - przy pomocy polecenia `kill` z poziomu powłoki.

---

## Zadanie b) Wysyłanie sygnałów między procesami

Uruchom program z punktu **a)** w procesie potomnym:

1. Utwórz proces potomny przy pomocy `fork()`.
2. W procesie potomnym uruchom program obsługi sygnałów za pomocą `execlp()`.
3. Z procesu macierzystego wysyłaj sygnały do procesu potomnego przy pomocy funkcji systemowej `kill()`.

### Wymagania

Przed wysłaniem sygnału:

- sprawdź, czy proces istnieje.

Po zakończeniu procesu potomnego:

- proces macierzysty powinien wywołać `wait()`,
- wypisać:
  - PID zakończonego procesu,
  - status zakończenia zwrócony przez `wait()`.

Jeżeli proces zakończył się wskutek otrzymania sygnału, należy dodatkowo wypisać:

- numer sygnału,
- nazwę sygnału (przy pomocy funkcji `strsignal()`).

Do odczytania numeru sygnału ze statusu zakończenia użyj odpowiednich makr opisanych w dokumentacji (np. `WIFSIGNALED`, `WTERMSIG`).

---

## Zadanie c) Sygnały dla grup procesów

W procesie macierzystym:

1. Utwórz proces potomny (`fork()`).
2. Ustaw go jako lidera nowej grupy procesów (`setpgid()`).
3. W tym procesie uruchom (`execlp()`) program, który:
   - tworzy kilka procesów potomnych (`fork()` w pętli),
   - każdy z nich uruchamia (`execlp()`) program do obsługi sygnałów z punktu **a)**.

### Następnie

Z pierwszego procesu macierzystego:

- wysyłaj sygnały do całej grupy procesów potomnych,
- przed wysłaniem sprawdź, czy grupa procesów istnieje,
- identyfikator grupy pobierz przy pomocy funkcji `getpgid()`.

### Dodatkowe wymagania

Proces będący liderem grupy procesów powinien:

- ignorować wysyłane sygnały,
- zaczekać na zakończenie wszystkich swoich procesów potomnych,
- dla każdego zakończonego procesu wypisać:
  - PID,
  - status zakończenia zwrócony przez `wait()`.

Jeżeli proces zakończył się wskutek sygnału, należy dodatkowo wypisać:

- numer sygnału,
- nazwę sygnału.

Pierwszy proces macierzysty również powinien:

- zaczekać na zakończenie swojego bezpośredniego potomka,
- wypisać:
  - PID,
  - status zakończenia zwrócony przez `wait()`.

---

## Parametry programu

We wszystkich programach:

- numer sygnału,
- sposób jego obsługi

powinny być przekazywane jako argumenty wiersza poleceń.

Program powinien:

- sprawdzać liczbę przekazanych argumentów,
- w przypadku błędnego uruchomienia wyświetlić komunikat o błędzie,
- podać krótką instrukcję poprawnego sposobu uruchomienia programu.
