# Laboratorium – Procesy w systemie Linux

## Ćwiczenie 1 – Procesy potomne (`fork`)

### Cel
Zapoznanie się z tworzeniem procesów potomnych przy użyciu funkcji `fork()` oraz analizą identyfikatorów procesów i grup procesów.

### Zadania

#### a) Wyświetlanie identyfikatorów procesu

Napisz program wypisujący następujące identyfikatory dla bieżącego procesu:

- UID (User ID)
- GID (Group ID)
- PID (Process ID)
- PPID (Parent Process ID)
- PGID (Process Group ID)

---

#### b) Tworzenie procesów potomnych

1. Wywołaj funkcję `fork()` **trzy razy** (najlepiej w pętli `for`).
2. Wypisz powyższe identyfikatory dla:
   - procesu macierzystego,
   - wszystkich procesów potomnych.
3. Najlepiej, aby każdy proces wypisywał informacje w **jednej linii**.
4. Użyj funkcji `wait()`, aby proces macierzysty czekał na zakończenie wszystkich procesów potomnych.

---

#### c) Adopcja procesów

Zmodyfikuj program z punktu **b)**:

- **Nie używaj funkcji `wait()`.**
- Użyj funkcji `sleep()`, aby proces macierzysty zakończył się wcześniej, dzięki czemu procesy potomne zostaną adoptowane przez proces `init` lub jego odpowiednik (np. `systemd`).

Następnie:

1. W powłoce wykonaj polecenie:

   ```bash
   pstree -p
   ```

2. Na wyświetlonym drzewie procesów zidentyfikuj proces, który adoptuje osierocone procesy w Twoim systemie.

---

#### d) Grupowanie procesów według pokoleń

Zmodyfikuj program z punktu **b)**:

- **Nie używaj funkcji `wait()`.**
- Umieść wywołania `sleep()` w odpowiednich miejscach programu tak, aby:
  - procesy pojawiały się na ekranie pokoleniami (od najstarszego do najmłodszego),
  - proces macierzysty kończył działanie dopiero po wszystkich procesach potomnych.

Na podstawie wyników:

1. Zapisz wyniki programu do pliku tekstowego.
2. Narysuj **drzewo genealogiczne procesów**, zaznaczając dla każdego procesu:
   - PID,
   - PPID,
   - PGID.

---

#### e) Własne grupy procesów

Zmodyfikuj program z punktu **b)**:

- Użyj funkcji `setpgid()`, aby każdy proces potomny stał się liderem własnej grupy procesów.

---

### Pytanie

**Ile procesów powstanie przy n-krotnym wywołaniu funkcji `fork()` i dlaczego?**

W moim systemie osierocone procesy adoptuje process "system", który ma PID 1.

Przy n-krotnym wywołaniu funkcji fork() powstanie 2^n procesów, ponieważ każdy proces (proces macieżysty) tworzy nowy process, czyli są 2 procesy. W kolejnym wywołaniu funkcji tworzone są 2 nowe procesy, są już 4. Każdy z tych 4 procesów przy 3 wywołaniu stworzy kolejny, więc będzie ich 8.

# Ćwiczenie 2 – Uruchamianie programów (`exec`)

### Cel

Zapoznanie się z rodziną funkcji `exec()` oraz zastępowaniem obrazu procesu.

### Zadanie

Zmodyfikuj program z ćwiczenia **1b** tak, aby:

- komunikaty procesów potomnych były wypisywane przez program uruchamiany za pomocą funkcji `execlp()`,
- nazwę programu uruchamianego przez `execlp()` przekazywać jako argument programu procesu macierzystego.

---

### Pytanie

**Ile procesów powstanie przy n-krotnym wywołaniu sekwencji `fork()` + `exec()` i dlaczego?**
