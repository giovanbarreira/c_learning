include make_defs

all: calc delta x1 x2

calc: calc.c
	$(CC) $(CFLAGS) -o calc calc.c

delta: delta.c eq2.c eq2.h
	$(CC) $(CFLAGS) -o delta delta.c eq2.c -lm

x1: x1.c eq2.c eq2.h
	$(CC) $(CFLAGS) -o x1 x1.c eq2.c -lm

x2: x2.c eq2.c eq2.h
	$(CC) $(CFLAGS) -o x2 x2.c eq2.c -lm

clean:
	rm -f calc delta x1 x2 *.o
