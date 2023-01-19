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
        r++;
        r += countNodes(t->left);
        r += countNodes(t->right);
    }
    return r;
}


struct treePair
{
    struct tree* source;
    struct tree** destination;
};

/*
 * This function add an id to the tree nodes (and reuses the values
 * from the previous tree so they should be immutable)
 */

struct tree *addId(struct tree *t)
{
    int id = 0;
    int nbNodes = countNodes(t);
    struct stack* s = newStack(nbNodes);
    // Add root node to stack
    struct treePair* root = malloc(sizeof(struct treePair));
    root->source = t;
    struct tree *r;
    root->destination = &r;
    push(s, root);

    while( !isEmpty(s) )
    {
        struct treePair* next;
        next = pop(s);
        // Add Id
        struct tree* destTree = malloc(sizeof(struct tree));
        struct idPair *idp = malloc(sizeof(struct idPair));
        idp->id = id++;
        idp->value = next->source->value;
        destTree->value = idp;
        destTree->left = NULL;
        destTree->right = NULL;
        *(next->destination) = destTree;

        // Add left/right to stack
        if (next->source->left) {
            struct treePair* tp = malloc(sizeof(struct treePair));
            tp->source = next->source->left;
            tp->destination = &(destTree->left);
            push(s,tp);
        }
        if (next->source->right) {
            struct treePair* tp = malloc(sizeof(struct treePair));
            tp->source = next->source->right;
            tp->destination = &(destTree->right);
            push(s,tp);
        }
        free(next);
    }
    freeStack(s);

    return r;
};

/* add method to free tree with Ids*/

void printTree(struct tree *t, int idIncluded)
{
    printf("(");
    if (t->value != NULL) 
    {
        if (idIncluded)
        {
            struct idPair* idp = (struct idPair*) t->value;
            printf("[%d,%s]", idp-> id, (char*) idp->value);
        }
        else
            printf("%s", (char*) t->value);
    }
    if (t->left != NULL)
    {
        printf(",");
        printTree(t->left, idIncluded);
    }
    if (t->right != NULL)
    {
        printf(","); 
        printTree(t->right, idIncluded);
    }
    printf(")");
};