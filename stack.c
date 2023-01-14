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

void freeStack(struct stack *s)
{
    free(s->elems);
    free(s);
}