#include <stdio.h>
#include <stdlib.h>

#include "bt.h"

Node* createRoot(int num) {
    Node* new = (Node *)malloc(sizeof(Node));
    new->data = num;
    return new;
}

// getRoot

// getParent

// getLeftest

// getRightest

// printTree

// insertTree

// deleteSubtree

// preorder

// inorder

// postorder

int main() {
    Node* new = createRoot(2);
    printf("Root's value: %d\n", new->data);
    return 0;
}
