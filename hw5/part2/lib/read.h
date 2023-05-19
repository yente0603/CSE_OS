#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h> //mmap()
#include <stddef.h>
#include "write.h"
#define _error(message)     \
    do                      \
    {                       \
        perror(message);    \
        exit(EXIT_FAILURE); \
    } while (0)
void test_read(const char *file, char *buf);
/*
1. file: the file you want to mmap and read as char*
2. buf: The buffer you provide to contain readed in data.
*/
#endif