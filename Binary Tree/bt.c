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

Node* getParent(Node* node) {
    if (node == NULL) {
        printf("Invalid input node!");
        return NULL;
    }

    return node->parent;
}

Node* getLeftest(Node* node) {
    Node* tmp = node;
    if (tmp == NULL) {
        printf("Invalid input node!");
        return NULL;
    }

    while (tmp->left != NULL) {
        tmp = tmp->left;
    }

    return tmp;
}

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
    // Node* tmp = new->right->left;
    // Node* tmp1 = getParent(tmp);
    // printf("Test value: %d\n", tmp1->data);
    // printf("NEW value: %d\n", new->right->parent->data);
    Node* tmp2 = getLeftest(new->right);
    printf("Test value: %d\n", tmp2->data);
    return 0;
}
