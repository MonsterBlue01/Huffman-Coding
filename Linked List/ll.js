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

// deleteNode

// insertNode

// clean

// getLength

// Find First Element

// Find Last Element

// push

// pop

// enqueue

// dequeue

// Insert Element At Index

int main() {
    LLNode* new = createNew(5);
    printf("%d\n", new->data);
}
