CC = gcc
CFLAGS = -Wall -fPIC -I. -pthread
LDFLAGS = -L. -lsema -pthread -lrt

# Nazwy plików wynikowych
TARGETS = Cw7 Producent Konsument
STATIC_LIBS = libsema.a libpamiec.a
SHARED_LIBS = libsema.so libpamiec.so

Plik1 ?= Dane1.txt
Plik2 ?= Dane2.txt

.PHONY: all clean run tar diff

all: $(STATIC_LIBS) $(SHARED_LIBS) $(TARGETS)

# Kompilacja pliku obiektowego
Semafory.o: Semafory.c Semafory.h Wspolny.h
	$(CC) $(CFLAGS) -c Semafory.c -o Semafory.o $(LDFLAGS)

# Tworzenie biblioteki statycznej
$(STATIC_LIBS): Semafory.o
	ar rcs $@ $^

# Tworzenie biblioteki dzielonej
$(SHARED_LIBS): Semafory.o
	$(CC) -shared -o $@ $^

PamiecDzielona.o: PamiecDzielona.c PamiecDzielona.h
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

# Kompilacja programów z biblioteką (STATIC/SHARED)
Cw7: Cw7.c PamiecDzielona.o $(STATIC_LIBS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

Producent: Producent.c PamiecDzielona.o $(STATIC_LIBS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

Konsument: Konsument.c PamiecDzielona.o $(STATIC_LIBS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o *.a *.so $(TARGETS)

run: Cw7
	LD_LIBRARY_PATH=. ./Cw7 $(Plik1) $(Plik2) ./Producent ./Konsument

diff:
	diff -s $(Plik1) $(Plik2)

TAR_NAZWA = Cwiczenie7.tar

tar:
	tar -cvf $(TAR_NAZWA) *.c *.h *.txt Makefile
