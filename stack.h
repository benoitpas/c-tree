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
int isEmpty(struct stack* s_);

#endif /* STACK_H */