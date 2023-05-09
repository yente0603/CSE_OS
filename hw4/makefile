CC = gcc

all : main

clean :
	rm -f *.o main

dep :
	$(CC) -MM *.c > dep

main : main.o mm.o
	$(CC) -o main main.o mm.o

mm.o : mm.c
	$(CC) -c mm.c

