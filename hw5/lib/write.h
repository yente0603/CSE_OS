#ifndef WRITE_H
#define WRITE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/mman.h> //mmap()
#define _error(message)     \
    do                      \
    {                       \
        perror(message);    \
        exit(EXIT_FAILURE); \
    } while (0)
void test_write(const char *file, const void *context);
/*
1. file: The file of file system, whitch mmaped into memory;
         If addr is NULL, then the kernel chooses the (page-aligned) address
         at which to create the mapping
2. context: The constext you want to write in.

reference: https://stackoverflow.com/a/26259596
*/
#endif