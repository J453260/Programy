GLOWNY = program

LINKER = gcc

CFLAGS = -Wall -Wextra -std=c99 -pedantic
BIBL = -lm

GLOKOM = main.o

$(GLOWNY): $(GLOKOM)
	$(LINKER) $(CFLAGS) -o $(GLOWNY) $(GLOKOM) $(BIBL)

%.o: %.c
	$(LINKER) $(CFLAGS) -c $< -o $@

clean:
	del -f $(GLOKOM) $(GLOWNY)
