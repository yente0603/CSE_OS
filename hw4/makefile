CC = gcc
FLAG = -Wall -std=c11
OUT = main.elf

all: dep
	$(CC) $(FLAG) *.o -o $(OUT)
dep: main.c mm.c
	$(CC) $(FLAG) -c mm.c
	$(CC) $(FLAG) -c main.c
clean:
	-rm $(OUT) *.o



