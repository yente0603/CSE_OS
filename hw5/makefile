CC = gcc

all: main.o read.o write.o
	$(CC) -o main.elf main.o read.o write.o
dep: main.c mm.c
	$(CC) -Wall -std=c11 -03 -c read.c
	$(CC) -Wall -std=c11 -03 -c write.c
	$(CC) -Wall -std=c11 -03 -c main.c
clean:
	-rm main.elf *.o