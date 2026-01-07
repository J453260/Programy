# Nazwa pliku wykonywalnego
GLOWYK = program

# Kompilator i linker
LINKER = gcc

# Flagi kompilatora i biblioteki
CFLAGS = -Wall -Wextra -std=c99 -pedantic
BIBL = -lm

# Pliki źródłowe i obiektowe
GLOKOM = main.o
FUNKOM = TypZespolone.o

# Główna reguła (kompilacja i linkowanie)
$(GLOWYK): $(GLOKOM) $(FUNKOM)
	$(LINKER) $(CFLAGS) -o $(GLOWYK) $(GLOKOM) $(FUNKOM) $(BIBL)

# Reguła kompilacji plików obiektowych
%.o: %.c
	$(LINKER) $(CFLAGS) -c $< -o $@

# Reguła czyszczenia plików tymczasowych
clean:
	del -f $(GLOKOM) $(FUNKOM) $(GLOWYK)
