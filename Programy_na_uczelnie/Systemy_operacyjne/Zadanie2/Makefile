# Nazwy plików wykonywalnych
BIN = ID cw2

# Kompilator i flagi
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2

# Cele Makefile
.PHONY: all clean run

# Kompilacja obu programów
all: $(BIN)

ID: ID.c
	$(CC) $(CFLAGS) -o $@ $<

cw2: cw2.c
	$(CC) $(CFLAGS) -o $@ $<

# Usuwanie plików wykonywalnych i tymczasowych
clean:
	rm -f $(BIN) *~ *.o

# Uruchamianie obu programów
run: all
	@echo "Uruchamianie ID..."
	@./ID
	@echo "Uruchamianie cw2..."
	@./cw2
# Nazwa archiwum
TAR_NAME = Cwiczenie2.tar

# Tworzenie archiwum tar i z plikami tekstowymi
tar: clean
	tar -cvf $(TAR_NAME) *.c Makefile *.txt
