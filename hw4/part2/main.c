#include <stdio.h>
#include <stdlib.h>
#include "mm.h"
int main()
{
    printf("testing mymalloc...\n");
    int *ptr = mymalloc(sizeof(int));
    if (ptr > 0)
    {
        *ptr = 8;
        printf("ptr = %d \n", *ptr);
        myfree(ptr);
        printf("executing free...\n");
    }
    else
        printf("malloc failed!\n");

    printf("testing mycalloc...\n");
    int size = 8;
    int *np = mycalloc(size, sizeof(int));
    if (np > 0)
    {
        for (int i = 0; i < size; i++)
            np[i] = i;
        for (int i = 0; i < size; i++)
            printf("np[%d] = %d \n", i, *(np + i));
    }
    else
        printf("calloc failed!\n");

    printf("testing myrealoc...\n");
    np = myrealloc(np, sizeof(int) * 16);
    if (np > 0)
        for (int i = 0; i < 16; i++)
            printf("np[%d] = %d \n", i, *(np + i));
    else
        printf("realloc failed!\n");
    return 0;
}