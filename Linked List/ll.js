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

// clean

// getLength

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

// pop

// enqueue

// dequeue

// Insert Element At Index

int main() {
    LLNode* new = createNew(5);
    push(new, 4);
    printf("%d\n", new->prev->next->data);
}
