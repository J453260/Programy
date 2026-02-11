CC=gcc
CFLAGS=-Wall -g -std=c99 -pedantic

MIN_SLEEP=1
MAX_SLEEP=3
LICZBA_KLIENTOW=2

OBJS=mqhelper.o
HEADERS=mqhelper.h

.PHONY: all clean tar xterm-run run-cw8

all: serwer klient Cw8

serwer: serwer.c $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -D MAX_KLIENCI=$(LICZBA_KLIENTOW) -o serwer serwer.c $(OBJS) -lrt

klient: klient.c $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o klient klient.c $(OBJS) -lrt

Cw8: Cw8.c
	$(CC) $(CFLAGS) -o Cw8 Cw8.c

mqhelper.o: mqhelper.c $(HEADERS)
	$(CC) $(CFLAGS) -c mqhelper.c

clean:
	rm -f *.o serwer klient Cw8

xterm-run: all
	xterm -hold -title SERWER -bg red -fg black -e ./serwer $(MIN_SLEEP) $(MAX_SLEEP) & \
	sleep 1 && \
	xterm -hold -title KLIENT1 -bg green -fg black -e ./klient $(MIN_SLEEP) $(MAX_SLEEP) & \
	xterm -hold -title KLIENT2 -bg green -fg black -e ./klient $(MIN_SLEEP) $(MAX_SLEEP) &

run-cw8: all
	./Cw8 ./serwer ./klient $(LICZBA_KLIENTOW) $(MIN_SLEEP) $(MAX_SLEEP)

TAR = Cwiczenie8.tar

tar:
	tar cvf $(TAR) *.c *.h *.txt Makefile
