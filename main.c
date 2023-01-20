#include <stdio.h>
#include "tree.h"

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

    printTree(&testa, 0);
    printf("\n");

    struct tree* testWithId;
    testWithId = addId(&testa);

    printTree(testWithId, 1);
    printf("\n");
    freeTree(testWithId);

    return 0;
}