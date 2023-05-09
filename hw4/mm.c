#include "mm.h"
#include <assert.h>
#include <string.h>
#include <unistd.h>
void *base = NULL;

typedef struct meta
{
    size_t size;
    int empty;
    struct meta *next;
} meta;

meta *need_space(size_t size, meta *tail)
{
    meta *cur;
    cur = (meta *)sbrk(0);
    void *need = sbrk(size + sizeof(meta));
    assert((void *)cur == need);
    if (need == (void *)-1)
    {
        return NULL;
    }
    if (tail != NULL)
    {
        tail->next = cur;
    }
    cur->size = size;
    cur->empty = 0;
    cur->next = NULL;
    return cur;
}

meta *find_empty_meta(size_t size, meta **tail)
{
    meta *cur = (meta *)base;
    while (cur && !(cur->size >= size && cur->empty == 1))
    {
        *tail = cur;
        cur = cur->next;
    }
    return cur;
}

void *mymalloc(size_t size)
{
    meta *cur;
    if (size <= 0)
    {
        return NULL;
    }

    if (base == NULL)
    {
        cur = need_space(size, NULL);
        if (cur == NULL)
        {
            return NULL;
        }
        base = cur;
    }
    else
    {
        meta *tail = (meta *)base;
        cur = find_empty_meta(size, &tail);
        if (cur == NULL)
        {
            cur = need_space(size, tail);
            if (cur == NULL)
            {
                return NULL;
            }
            else
            {
                cur->empty = 0;
            }
        }
    }
    return (cur + 1);
}

void myfree(void *ptr)
{
    if (ptr == NULL)
        return;
    meta *free_ptr = (meta *)ptr - 1;
    assert(free_ptr->empty == 0);
    free_ptr->empty = 1;
}

void *myrealloc(void *ptr, size_t size)
{
    if (ptr == NULL)
        return mymalloc(size);
    meta *p = (meta *)ptr - 1;
    if (p->size >= size)
        return ptr;

    void *newp = mymalloc(size);
    if (newp == NULL)
        return NULL;

    memset(newp, 0, size);
    memcpy(newp, ptr, p->size);
    myfree(ptr);

    return newp;
}

void *mycalloc(size_t nmemb, size_t size)
{
    size_t total = nmemb * size;
    void *p = mymalloc(total);
    if (p == NULL)
    {
        return NULL;
    }
    memset(p, 0, total);
    return p;
}
