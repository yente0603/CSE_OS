CC = g++
CFLAGS = -Wall -std=c++11 
src = src
all: dep
	$(CC) $(CFLAGS) main.o read.o write.o -o main.elf
dep:
	$(CC) $(CFLAGS) -c $(src)/read.c
	$(CC) $(CFLAGS) -c $(src)/write.c
	$(CC) $(CFLAGS) -c main.cpp
clean:
	-rm main.elf $(src)/*.o *.o test.txt