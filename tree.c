#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "tree.h"

/*
 * Note: As a recursive function this is not really
 * idiomatic C code.
 */
int countNodes(struct tree *t)
{
    int r = 0;
    if (t != NULL) {
        if ((*t).left != NULL) {
            r += ((*t).left != NULL ? countNodes((*t).left) : 0);
        }
    }
    return r;
}


struct treePair
{
    struct tree source;
    void** destination;
};

/*
 * This function add an id to the tree nodes (and reuses the values
 * from the previous tree so they should be immutable)
 */

struct tree *addId(struct tree *t)
{
    int nbNodes = countNodes(t);
    struct stack* s = newStack(nbNodes);
    while( !isEmpty(s) )
    {
        // pop, add id
    }
    freeStack(s);
    return t;
};


void printTree(struct tree *t)
{
    printf("(");
    if (t->value != NULL) 
    {
        printf("%s", (char*) t->value);
    }
    if (t->left != NULL)
    {
        printf(",");
        printTree(t->left);
    }
    if (t->right != NULL)
    {
        printf(","); 
        printTree(t->right);
    }
    printf(")");
};