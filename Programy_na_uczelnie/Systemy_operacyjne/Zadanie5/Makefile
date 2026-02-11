CC = gcc
CFLAGS = -Wall -std=c99 -pedantic

# Pliki źródłowe
SRC_PROD = Producent.c
SRC_KONS = Konsument.c
SRC_MAIN = 5a.c

# Pliki wynikowe
BIN_PROD = Producent
BIN_KONS = Konsument
BIN_MAIN = 5a

# Nazwy plików danych
PlikWejsciowy = dane.txt
PlikWyjsciowy = wyniki.txt
Min = 1
Max = 3
Buf_prod = 5
Buf_kons = 5

# Plik FIFO
FIFO = mojefifo

.PHONY: all run xterm fifo rmfifo diff clean tar

all: $(BIN_PROD) $(BIN_KONS) $(BIN_MAIN)

$(BIN_PROD): $(SRC_PROD)
	$(CC) $(CFLAGS) -o $@ $<

$(BIN_KONS): $(SRC_KONS)
	$(CC) $(CFLAGS) -o $@ $<

$(BIN_MAIN): $(SRC_MAIN)
	$(CC) $(CFLAGS) -o $@ $<

run:
	@if [ ! -p $(FIFO) ]; then mkfifo $(FIFO); fi
	xterm -hold -title "5a" -e ./$(BIN_MAIN) $(PlikWejsciowy) $(PlikWyjsciowy) $(Min) $(Max) $(Buf_prod) $(Buf_kons) ./$(BIN_PROD) ./$(BIN_KONS)

fifo:
	@if [ ! -p $(FIFO) ]; then mkfifo $(FIFO); fi

rmfifo:
	rm -f $(FIFO)

xterm:
	xterm -hold -title "PRODUCENT" -e ./$(BIN_PROD) $(FIFO) $(PlikWejsciowy) $(Min) $(Buf_prod) & \
	xterm -hold -title "KONSUMENT" -e ./$(BIN_KONS) $(FIFO) $(PlikWyjsciowy) $(Max) $(Buf_kons) &

diff:
	diff -s $(PlikWejsciowy) $(PlikWyjsciowy)

clean:
	rm -f $(BIN_PROD) $(BIN_KONS) $(BIN_MAIN) $(FIFO) $(PlikWyjsciowy)

TAR_NAME = Cwiczenie5.tar

tar: clean
	tar -cvf $(TAR_NAME) *.txt *.c Makefile
