#Zmienne
Liczba_watkow = 5
Cykle = 3
Min = 1
Max = 3

# Nazwa pliku wynikowego
TARGET = Cw9

# Kompilator
CC = gcc

# Flagi kompilatora
CFLAGS = -Wall -Wextra -pedantic -std=c11 -pthread

# Pliki źródłowe
SRCS = Cw9.c

# Reguła domyślna (pierwsza)
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

#Uruchamianie programu
run: all
	./$(TARGET) $(Liczba_watkow) $(Cykle) $(Min) $(Max)

# Czyszczenie plików tymczasowych
clean:
	rm -f $(TARGET)

#Tar
TAR = Cwiczenie9.tar

tar:
	tar cvf $(TAR) *.c  *.txt Makefile
