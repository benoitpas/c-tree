#ifndef TREE_H
#define TREE_H

struct tree
{
    struct tree *left;
    struct tree *right;
    void *value;         
};

#endif /* TREE_H */