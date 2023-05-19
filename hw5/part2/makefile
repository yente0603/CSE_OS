CC = gcc
CFLAGS = -Wall -std=gnu99
SRC = src
all: dep
	$(CC) $(CFLAGS) *.o -o main.elf
dep:
	$(CC) $(CFLAGS) -c $(SRC)/read.c
	$(CC) $(CFLAGS) -c $(SRC)/write.c
	$(CC) $(CFLAGS) -c main.c
clean:
	-rm main.elf *.o test.txt
