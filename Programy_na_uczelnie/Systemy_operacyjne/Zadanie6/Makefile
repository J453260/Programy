# Nazwa programów wynikowych
EXEC = Cw6
SEK = Sekcja_krytyczna

Min = 1
Max = 3
Plik = numer.txt
Semafor = mojsem
N = 10

# Kompilator i flagi
CC = gcc
CFLAGS = -Wall -Wextra -O2 -pedantic -std=c99 -pthread

# Pliki źródłowe
SRCS = Cw6.c Semafory.c
SEK_SRCS = Sekcja_krytyczna.c Semafory.c

# Domyślny cel
all: $(EXEC) $(SEK)

# Kompilacja głównego programu
$(EXEC):
	$(CC) $(CFLAGS) -o $(EXEC) $(SRCS)

# Kompilacja sekcji krytycznej
$(SEK):
	$(CC) $(CFLAGS) -o $(SEK) $(SEK_SRCS)

# Uruchomienie programu
run: $(EXEC) $(SEK)
	./$(EXEC) $(Plik) $(Min) $(Max) $(Semafor) ./$(SEK) $(N)

# Czyszczenie plików wynikowych
clean:
	rm -f $(EXEC) $(SEK)

# Reset środowiska (plik + semafor)
reset:
	rm -f $(Plik)

.PHONY: all clean reset run tar

TAR_NAME = Cwiczenie6.tar

tar: clean
	tar -cvf $(TAR_NAME) *.txt *.c Makefile
