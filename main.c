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

    printTree(&testa);     
   return 0;
}