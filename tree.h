#ifndef TREE_H
#define TREE_H

struct tree
{
    struct tree *left;
    struct tree *right;
    void *value;         
};

struct idPair
{
    int id;
    void *value;
};


int countNodes(struct tree *t);
struct tree *addId(struct tree *t);
void printTree(struct tree *t, int idIncluded);

#endif /* TREE_H */