CC = g++
src = src
all: main.o $(src)/read.o $(src)/write.o
	$(CC) -o main.elf main.o $(src)/read.o $(src)/write.o
dep: main.cpp $(src)/read.c $(src)/write.c
	$(CC) -Wall -std=c11 -03 -c $(src)/read.c
	$(CC) -Wall -std=c11 -03 -c $(src)/write.c
	$(CC) -Wall -std=c11 -03 -c main.cpp
clean:
	-rm main.elf $(src)/*.o *.o file.txt