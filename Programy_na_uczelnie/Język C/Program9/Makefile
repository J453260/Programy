# Nazwa pliku wykonywalnego
EXEC = program

# Kompilator i flagi
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -fopenmp -g

# Pliki źródłowe i obiektowe
SRC = main.c OperacjeMacierzowe.c
OBJ = main.o OperacjeMacierzowe.o

# Reguła domyślna
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Reguły dla plików obiektowych
main.o: main.c OperacjeMacierzowe.h
	$(CC) $(CFLAGS) -c main.c -o main.o

OperacjeMacierzowe.o: OperacjeMacierzowe.c OperacjeMacierzowe.h
	$(CC) $(CFLAGS) -c OperacjeMacierzowe.c -o OperacjeMacierzowe.o

# Czyszczenie
clean:
	rm -f $(OBJ) $(EXEC)
