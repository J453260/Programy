# Opis programów

## 3a
Program demonstruje różne sposoby obsługi sygnałów w systemie Linux. Umożliwia:
- domyślną obsługę sygnału,
- ignorowanie sygnału,
- przechwycenie sygnału i obsłużenie go własną funkcją.

Program można przetestować m.in. z sygnałem `SIGINT` wywoływanym skrótem **Ctrl + C**.

## 3b
Program tworzy proces potomny za pomocą `fork()`, uruchamia wskazany program przy użyciu `execlp()`, a następnie z procesu macierzystego wysyła do niego sygnał `SIGKILL`. Po zakończeniu procesu wyświetlana jest informacja, czy został zakończony przez sygnał.

## 3c1
Program tworzy trzy procesy potomne, z których każdy uruchamia program `3a` z innym sposobem obsługi sygnału. Pozwala porównać zachowanie procesów przy domyślnej obsłudze sygnału, ignorowaniu sygnału oraz własnej obsłudze. Proces macierzysty oczekuje na zakończenie wszystkich procesów i wyświetla sposób ich zakończenia.

## 3c2
Program demonstruje działanie grup procesów. Proces potomny tworzy własną grupę procesów (`setpgid()`), uruchamia wskazany program, a proces macierzysty wysyła sygnał `SIGINT` do całej grupy za pomocą `kill(-PGID, SIGINT)`. Następnie wyświetlana jest informacja o sposobie zakończenia lidera grupy.
