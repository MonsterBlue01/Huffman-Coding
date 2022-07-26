#include <stdio.h>
#include <stdlib.h>

#include "bt.h"

Node* createnode(int num) {
    Node* new = (Node *)malloc(sizeof(Node));
    new->data = num;
    return new;
}

Node* getnode(Node* node) {
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

Node* getRightest(Node* node) {
    Node* tmp = node;
    if (tmp == NULL) {
        printf("Invalid input node!");
        return NULL;
    }

    while (tmp->right != NULL) {
        tmp = tmp->right;
    }

    return tmp;
}

void helpF(Node* node, int n) {
    if (node == NULL) {
        printf("NO");
        return;
    }

    n += 10;
    helpF(node->right, n);
    printf("\n");
    for (int i = 10; i < n; i++) {
        printf(" ");
    }
    printf("%d\n", node->data);
    helpF(node->left, n);
}


void printTree(Node* node) {
    helpF(node, 0);
}

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

void deleteSubtree(Node* node) {
    if (node != NULL) {
        node->left = NULL;
        node->right = NULL;
    }

    if (node->parent != NULL) {
        if (node->data < node->parent->data) {
            node->parent->left = NULL;
        } else if (node->data > node->parent->data) {
            node->parent->right = NULL;
        }
    }
}

void preorder(Node* node) {
    if (node == NULL) {
        return;
    }

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node) {
    if (node == NULL) {
        return;
    }

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void postorder(Node* node) {
    if (node == NULL) {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

// tips: Put the root node in
void deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }

    node->data = 0;
    node->left = NULL;
    node->right = NULL;
}

int main(void) {
    Node* new = createnode(4);
    insert(2, new);
    insert(6, new);
    insert(1, new);
    insert(3, new);
    insert(5, new);
    insert(7, new);
    // Node* tmp = new->right->left;
    // Node* tmp1 = getParent(tmp);
    // printf("Test value: %d\n", tmp1->data);
    // printf("NEW value: %d\n", new->right->parent->data);
    // Node* tmp2 = getLeftest(new->right);
    // printf("Test value: %d\n", tmp2->data);
    // Node* tmp3 = new->left;
    // deleteSubtree(tmp3);
    // preorder(new);
    // printf("\n");
    // inorder(new);
    // printf("\n");
    // postorder(new);
    deleteTree(new);
    printTree(new);
    return 0;
}
