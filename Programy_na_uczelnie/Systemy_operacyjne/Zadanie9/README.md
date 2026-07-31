# Autor: Jan Bajor
# Data: 25.05.2025
# Miejsce: Kraków

Folder zawiera 1 kod realizujący wzajemne wykluczanie dla wątków standardu POSIX z użyciem muteksów.
Najpierw mutex zostaje zainicjalizowany. Potem w pętli wątki są tworzone i dla każdego wątku jest uruchamiana funkcja "watek_funkcja".
W niej każdy wątek przechodzi przez sekcje prywatną i sekcję krytyczną inkrementując licznik.

Po zakończeniu pierwszej pętli druga pętla czeka na zakończenie wszystkich wątków, po czym następuje usunięcie mutexa, zwolnienie pamięci i zakonczenie programu.
