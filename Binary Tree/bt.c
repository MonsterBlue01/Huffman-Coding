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

Node* insert(int num, Node* node) {
    if (node == NULL) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = num;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (num < node->data) {
        node->left = insert(num, node->left);
    } else if (num > node->data) {
        node->right = insert(num, node->right);
    }
    
    return node;
}

// deleteSubtree

// preorder

// inorder

// postorder

int main(void) {
    Node* new = createRoot(2);
    insert(8, new);
    insert(4, new);
    printf("NEW value: %d\n", new->right->left->data);
    return 0;
}
