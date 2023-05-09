CC = gcc

all: main.o mm.o
	$(CC) -o main.elf main.o mm.o
dep: main.c mm.c
	$(CC) -Wall -std=c11 -03 -c mm.c
	$(CC) -Wall -std=c11 -03 -c main.c
clean:
	-rm main.elf *.o