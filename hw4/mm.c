#include "mm.h"

// for use c++ keyword and function
#define nullptr NULL
#define constexpr const

typedef struct _Block
{
    size_t size;
    struct _block *next;
} Block;

void *mymalloc(size_t size);
void *myfree(void *ptt);
void *myrealloc(void *ptr, size_t size);
void *mycalloc(size_t nmemb, size_t size);