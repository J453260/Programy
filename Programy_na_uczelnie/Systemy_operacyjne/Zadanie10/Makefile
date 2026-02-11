#Zmienne
LICZBA_WATKOW = 5
CYKLE = 3
MIN = 1
MAX = 3

# Nazwa pliku wynikowego
TARGET = Cw10

# Kompilator
CC = gcc

# Flagi kompilatora
CFLAGS = -Wall -Wextra -pedantic -std=c11

# Pliki źródłowe
SRCS = Cw10.c

.PHONY: all run clean tar

# Reguła domyślna (pierwsza)
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) -lpthread

#Uruchamianie programu
run: all
	./$(TARGET) $(LICZBA_WATKOW) $(CYKLE) $(MIN) $(MAX)

# Czyszczenie plików tymczasowych
clean:
	rm -f $(TARGET)

#Tar
TAR = Cwiczenie10.tar

tar:
	tar cvf $(TAR) *.c *.txt Makefile
