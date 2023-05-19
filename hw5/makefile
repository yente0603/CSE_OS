CC = gcc
CFLAGS = -Wall -std=c11 
SRC = src
all: dep
	$(CC) $(CFLAGS) main.o read.o write.o -o main.elf
dep:
	$(CC) $(CFLAGS) -c $(SRC)/read.c
	$(CC) $(CFLAGS) -c $(SRC)/write.c
	$(CC) $(CFLAGS) -c main.c
clean:
	-rm main.elf $(src)/*.o *.o test.txt


# CC = gcc
# CFLAGS = -Wall -W -Og -g -std=gnu99
# SRC = src
# OUT = main.elf

# all: dep
# 	$(CC) $(CFLAGS) *.o -o $(OUT)

# dep: 
# 	$(CC) $(CFLAGS) -c $(SRC)/read.c
# 	$(CC) $(CFLAGS) -c $(SRC)/write.c
# 	$(CC) $(CFLAGS) -c main.c

# clean:
# 	rm -f $(OUT) *.o .gdb_history peda-session-* *.so test.txt $(src)/*.o

# check:
# 	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all ./$(OUT)

# help:
# 	@printf "make clean dep all:			to make clean and all\n"
# 	@printf "make check				to make check memory by valgrind\n"
