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



# CC = gcc

# all : main

# clean :
# 	rm -f *.o main

# dep :
# 	$(CC) -MM *.c > dep

# main : main.o mm.o
# 	$(CC) -o main main.o mm.o

# mm.o : mm.c
# 	$(CC) -c mm.c




