#include "mm.h"
#include <assert.h>
#include <string.h>
#include <unistd.h>
void *base = NULL;
typedef struct block
{
    size_t size, empty;
    struct block *next;
} block;

block *space(size_t size, block *tail)
{
    block *current;
    current = (block *)sbrk(0);
    void *need = sbrk(size + sizeof(block));
    assert((void *)current == need);
    if (need == (void *)-1)
        return NULL;
    if (tail != NULL)
        tail->next = current;
    current->size = size;
    current->empty = 0;
    current->next = NULL;
    return current;
}

block *find_empty_block(size_t size, block **tail)
{
    block *current = (block *)base;
    while (current && !(current->size >= size && current->empty == 1))
    {
        *tail = current;
        current = current->next;
    }
    return current;
}
void *mymalloc(size_t size)
{
    block *current;
    if (size <= 0)
        return NULL;
    if (base == NULL)
    {
        current = space(size, NULL);
        if (current == NULL)
            return NULL;
        base = current;
    }
    else
    {
        block *tail = (block *)base;
        current = find_empty_block(size, &tail);
        if (current == NULL)
        {
            current = space(size, tail);
            if (current == NULL)
                return NULL;
            else
                current->empty = 0;
        }
    }
    return (current + 1);
}
void myfree(void *ptr)
{
    if (ptr == NULL)
        return;
    block *free_ptr = (block *)ptr - 1;
    assert(free_ptr->empty == 0);
    free_ptr->empty = 1;
}
void *myrealloc(void *ptr, size_t size)
{
    if (ptr == NULL)
        return mymalloc(size);
    block *p = (block *)ptr - 1;
    if (p->size >= size)
        return ptr;

    void *np = mymalloc(size);
    if (np == NULL)
        return NULL;
    memset(np, 0, size);
    memset(np, ptr, p->size);
    myfree(ptr);

    return np;
}
void *mycalloc(size_t nmemb, size_t size)
{
    size_t total = nmemb * size;
    void *p = mymalloc(total);
    if (p == NULL)
        return NULL;
    memset(p, 0, total);
    return p;
}