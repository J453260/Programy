CC = gcc
CFLAGS = -Wall -std=c99 -pedantic

EXEC = Cw4
SRC = Cw4.c

.PHONY: all clean tar diff run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXEC)

TAR_NAME = Cwiczenie4.tar
tar: clean
	tar -cvf $(TAR_NAME) *.c *.txt Makefile

run: all
	./Cw4 Dane1.txt Dane2.txt 2 4

diff:
	diff -s Dane1.txt Dane2.txt
