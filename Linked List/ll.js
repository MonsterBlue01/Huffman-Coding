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

// Tips: It counts from 0, but not 1.
int findFirst(int element, LLNode* node) {
    int index = 0;
    LLNode* tmp = node;
    while (tmp->prev != NULL) {
        tmp = tmp->prev;
    }
    while (tmp != NULL) {
        if (tmp->data == element) {
            return index;
        }
        index++;
        tmp = tmp->next;
    }
    return -1;
}

int findLast(int element, LLNode* node) {
    int index = 0;
    LLNode* tmp = node;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        printf("%d\n", tmp->data);
    }
    while (tmp != NULL) {
        if (tmp->data == element) {
            return getLength(node) - index - 1;
        }
        index++;
        tmp = tmp->prev;
    }
    return -1;
}

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

void enqueue(LLNode* node, int val) {
    LLNode* tmp = node;
    LLNode* new = (LLNode *)malloc(sizeof(LLNode));
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    new->data = val;
    tmp->next = new;
    new->prev = tmp;
    new->next = NULL;
}

void dequeue(LLNode* node) {
    LLNode* tmp = node;
    while (tmp->prev != NULL) {
        tmp = tmp->prev;
    }
    LLNode* head = tmp;
    tmp->next->prev = NULL;
    free(head);
}

void to_string(LLNode* node) {
    LLNode* tmp = node;
    while (tmp->prev != NULL) {
        tmp = tmp->prev;
    }
    while (tmp->next != NULL) {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->data);
}

void insertAtIndex(LLNode* ll, int index, int val) {
    if ((index > getLength(ll) - 1) || (index < 0)) {
        printf("The corresponding index does not exist.\n");
        return;
    } else if (index == getLength(ll) - 1) {
        enqueue(ll, val);
        return;
    }
    LLNode* tmp = ll;
    LLNode* new = (LLNode *)malloc(sizeof(LLNode));
    new->data = val;
    while (tmp->prev != NULL) {
        tmp = tmp->prev;
    }
    int realI = 0;
    if (index == 0) {
        tmp->next->prev = new;
        new->prev = tmp;
        new->next = tmp->next;
        tmp->next = new;
        return;
    }
    while (realI != index) {
        tmp = tmp->next;
        if (realI == index - 1) {
            printf("%d\n", tmp->data);
            tmp->next->prev = new;
            new->prev = tmp;
            new->next = tmp->next;
            tmp->next = new;
        }
        realI++;
    }
}

// Insert Element At Index

// Merge

// RemoveFirst

// RemoveLast

// RemoveIndex

// Contains

// Get (Get an element at a specified position)

// GetFirst

// GetLast

// Clone

int main() {
    LLNode* new = createNew(5);
    push(new, 4);
    push(new, 3);
    // push(new, 6);
    push(new, 3);
    push(new, 2);
    push(new, 1);
    // printf("%d\n", getLength(new));
    // printf("%d\n", findFirst(3, new));
    // printf("%d\n", findLast(3, new));
    // enqueue(new, 3);
    dequeue(new);
    enqueue(new, 6);
    insertAtIndex(new, -1, 4);
    to_string(new);
    clean(new);
    // pop(new);
    // pop(new);
    // pop(new);
    // pop(new);
    // printf("%d\n", new->prev->next->data);
}
