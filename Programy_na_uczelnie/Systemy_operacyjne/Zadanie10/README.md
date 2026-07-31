Autor: Jan Bajor

Data: 02.06.2025

Miejsce: Kraków

Folder zawiera 1 kod: Cw10.c, zawierający implementacje algorytmu piekarni wraz ze wzajemnym wykluczaniem wątków standardu POSIX.
W funkcji "funkcja_watek" każdy wątek przechodzi przez sekcje prywatną i sekcję krytyczną inkrementując licznik, ale wewnątrz funkcji jest algorytm piekarni,
który zapewnia to, że do sekcji krytycznej wejdzie tylko jeden wątek.

Argumenty wejścia programu są zmiennymi w Makefile.
