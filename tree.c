#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

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

/*
 * This function add an id to the tree nodes (and reuses the values
 * from the previous tree so they should be immutable)
 */
struct tree *addId(struct tree *t)
{
    int nbNodes = countNodes(t);
    struct tree**stack = malloc(sizeof(struct tree *) * nbNodes);
    int id = 0;
    int nStack = 1;
    struct tree **stackP = stack;
    *stackP = t;
    while( nStack > 0 )
    {
        // pop, add id
    }
    free(stack);
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

#ifndef UNIT_TEST
int main() {
    struct tree testa;
    struct tree testb;
    struct tree testc;
    struct tree testd;
    struct tree teste;
    testa.value = "A";
    testa.left = &testb;
    testa.right = &testc;
    testb.value = "B";
    testc.value = "C";
    testc.left = &testd;
    testc.right = &teste;
    testd.value = "D";
    teste.value = "E";

    printTree(&testa);     
   return 0;
}
#endif