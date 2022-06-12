#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

LLNode* createNew(int val) {
    LLNode* new = (LLNode *)malloc(sizeof(LLNode));
    new->data = val;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

int getLength(LLNode* node) {
    int num = 0;

    while (node->prev != NULL) {
        node = node->prev;
    }

    while (node->next != NULL) {
        num++;
        node = node->next;
    }

    return num + 1;
}

// Find First Element

// Find Last Element

void push(LLNode* node, int val) {
    LLNode* new = (LLNode *)malloc(sizeof(LLNode));
    LLNode* tmp = node;
    while (tmp->prev != NULL) {
        tmp = tmp->prev;
    }
    new->data = val;
    tmp->prev = new;
    new->next = tmp;
}

void pop(LLNode* node) {
    LLNode* tmp = node;
    while (tmp->prev != NULL) {
        tmp = tmp->prev;
    }

    if ((node->prev == NULL) && (node->next == NULL)) {
        free(node);
        return;
    }

    if (tmp) {
        tmp->next->prev = NULL;
        tmp = NULL;
        free(tmp);
    }
}

void clean(LLNode* node) {
    LLNode* tmp = node;
    while (tmp->prev != NULL) {
        tmp = tmp->prev;
    }
    while (tmp != NULL) {
        // printf("%d\n", tmp->data);
        LLNode* del = tmp;
        tmp = tmp->next;
        free(del);
    }
}

// enqueue

// dequeue

// Insert Element At Index

int main() {
    LLNode* new = createNew(5);
    push(new, 4);
    push(new, 3);
    push(new, 2);
    // printf("%d\n", getLength(new));
    clean(new);
    // pop(new);
    // pop(new);
    // pop(new);
    // pop(new);
    // printf("%d\n", new->prev->next->data);
}
