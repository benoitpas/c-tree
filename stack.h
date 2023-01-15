#ifndef STACK_H
#define STACK_H

struct stack
{
    void **elems;
    int maxElems;
    void **currentElem;
};

struct stack* newStack(int maxElems);
void freeStack(struct stack *s);

int push(struct stack* s, void* p);
void* pop(struct stack* s);

#endif /* STACK_H */