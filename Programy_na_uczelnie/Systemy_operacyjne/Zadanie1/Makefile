# Lista programów
EXEC = 1a 1b 1c 1d 1e

# Kompilator
CC = gcc

# Flagi kompilatora
CFLAGS = -Wall -Wextra -std=c11 -O2

.PHONY: all clean run

# Kompilacja wszystkich programów
all: $(EXEC)

# Reguła ogólna dla każdego programu
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Usuwanie wszystkich plików wykonywalnych i tymczasowych
clean:
	rm -f $(EXEC) *.o *~

# Uruchamianie wszystkich programów sekwencyjnie
run: all
	@echo "Uruchamianie programów..."
	@./1a
	@./1b
	@./1c
	@./1d
	@./1e
