#include <stdio.h>
#include <stdlib.h>

#include "bt.h"

Node* createRoot(int num) {
    Node* new = (Node *)malloc(sizeof(Node));
    new->data = num;
    return new;
}

Node* getRoot(Node* node) {
    Node* tmp = node;
    while (tmp->parent != NULL) {
        tmp = tmp->parent;
    }
    return tmp;
}

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
        Node* tmp = insert(num, node->left);
        node->left = tmp;
        tmp->parent = node;
    } else if (num > node->data) {
        Node* tmp = insert(num, node->right);
        node->right = tmp;
        tmp->parent = node;
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
    printf("NEW value: %d\n", new->right->parent->data);
    return 0;
}
