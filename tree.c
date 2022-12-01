#include <stdio.h>

#include "tree.h"

int countNodes(struct tree *t) {
    int r = 0;
    if (t != NULL) {
        if ((*t).left != NULL) {
            r += ((*t).left != NULL ? countNodes((*t).left) : 0);
        }
    }
    return r;
}

#ifndef UNIT_TEST
int main() {
    struct tree test;
    
   /* printf() displays the string inside quotation */
   printf("Hello, World!");
   return 0;
}
#endif