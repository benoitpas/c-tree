#include "stack.h"
#include <stdlib.h>

struct stack* newStack(int maxElems)
{
    void* elems = malloc(sizeof(void*)*maxElems);
    struct stack* r = malloc(sizeof(struct stack));
    r->currentElem = elems;
    r->elems = elems;
    r->maxElems = maxElems;
    return r;
}

/*
 * Adds an element to the stack,
 * returns 0 if element succesfully added
 * or another value in case of failure (stack full most likely)
 */
int push(struct stack* s, void* p)
{
    int r = -1;
    void** maxPointer = s->elems + s->maxElems * sizeof(void*);
    if (s->currentElem < maxPointer)
    {
        *s->currentElem = p;
        s->currentElem = s->currentElem + 1;
        r = 0;
    }
    return r;
};

/*
 * Removes an element from the stack and returns it.
 * If the stack is empty, returns a NULL pointer
 */
void* pop(struct stack* s)
{
    void* r = NULL;
    if (s->elems < s->currentElem) {
        r = *(--s->currentElem);
    }
    return r;
};

void freeStack(struct stack *s)
{
    free(s->elems);
    free(s);
}