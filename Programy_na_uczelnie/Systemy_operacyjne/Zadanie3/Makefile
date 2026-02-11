# Kompilator i flagi
CC = gcc
CFLAGS = -Wall -std=c99 -pedantic

# Pliki wykonywalne
EXEC1 = 3a
EXEC2 = 3b
EXEC3 = 3c
EXEC4 = 3c2

# Pliki źródłowe
SRC1 = 3a.c
SRC2 = 3b.c
SRC3 = 3c.c
SRC4 = 3c2.c

# Reguła domyślna (kompilacja wszystkich programów)
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4)

# Kompilacja i linkowanie w jednym kroku (bez plików .o)
$(EXEC1): $(SRC1)
	$(CC) $(CFLAGS) -o $@ $<

$(EXEC2): $(SRC2)
	$(CC) $(CFLAGS) -o $@ $<

$(EXEC3): $(SRC3)
	$(CC) $(CFLAGS) -o $@ $<

$(EXEC4): $(SRC4)
	$(CC) $(CFLAGS) -o $@ $<

# Reguła do usuwania plików wykonywalnych
clean:
	rm -f $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4)

# Reguła do tworzenia archiwum tar
TAR_NAME = Sygnaly.tar

tar: clean
	tar -cvf $(TAR_NAME) *.c *.txt Makefile

# Reguła uruchamiania wszystkich programów z argumentami
run: all
	@echo "Uruchamianie programu 3a z argumentami..."
	@./3a 2 1
	@echo "Uruchamianie programu 3b z argumentami..."
	@./3b ./3a 2 2
	@echo "Uruchamianie programu 3c z argumentami..."
	@./3c ./3c2
