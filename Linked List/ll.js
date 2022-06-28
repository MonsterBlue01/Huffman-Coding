#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

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
            tmp->next->prev = new;
            new->prev = tmp;
            new->next = tmp->next;
            tmp->next = new;
        }
        realI++;
    }
}

// Tips: Merge the second string of Nodes into the first string of Nodes and free all nodes in the second string.
LLNode* merge(LLNode* one, LLNode* two) {
    LLNode* tmp = two;
    if (one == NULL) {
        one = two;
        clean(two);
        return two;
    }
    for(; two->prev != NULL; two = two->prev);
    while (two != NULL) {
        enqueue(one, two->data);
        two = two->next;
    }
    clean(tmp);
    return one;
}

void removeIndex(LLNode* ll, int index) {
    if (index == 0) {
        dequeue(ll);
        return;
    } else if (index == getLength(ll) - 1) {
        LLNode* tmp = ll;
        for (; tmp->next != NULL; tmp = tmp->next);
        LLNode* p = tmp->prev;
        p->next = NULL;
        free(tmp);
        return;
    }

    LLNode* t = ll;
    for (; t->prev != NULL; t = t->prev);
    int tmp = index;
    while (tmp > 0) {
        t = t->next;
        tmp--;
    }
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

bool contains(LLNode* ll, int element) {
    LLNode* tmp = ll;
    for (; tmp->prev != NULL; tmp = tmp->prev);
    while (tmp != NULL) {
        if (tmp->data == element) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

int get(LLNode* ll, int index) {
    if ((index < 0) || (index > getLength(ll) - 1)) {
        printf("The corresponding index does not exist.\n");
        return INT32_MIN;
    }
    LLNode* tmp = ll;
    for (; tmp->prev != NULL; tmp = tmp->prev);
    int temp = index;
    while (temp != 0) {
        tmp = tmp->next;
        temp--;
    }
    return tmp->data;
}

int getFirst(LLNode* ll) {
    LLNode* tmp = ll;
    for (; tmp->prev != NULL; tmp = tmp->prev);
    return tmp->data;
}

int getLast(LLNode* ll) {
    LLNode* tmp = ll;
    for (; tmp->next != NULL; tmp = tmp->next);
    return tmp->data;
}

// tips: Because cloning an empty linked list doesn't make any sense, I just 
// ignored that case when writing this function (because at least one LLNode* 
// needs to be passed in).
LLNode* clone(LLNode* ll) {
    LLNode* tmp = ll;
    for (; tmp->prev != NULL; tmp = tmp->prev);
    LLNode* new = createNew(tmp->data);
    tmp = tmp->next;
    for (; tmp != NULL; tmp = tmp->next) {
        enqueue(new, tmp->data);
    }
    return new;
}

int main(void) {
    LLNode* new = createNew(5);
    push(new, 4);
    push(new, 3);
    push(new, 2);
    push(new, 1);
    LLNode* ano = createNew(8);
    push(ano, 7);
    // printf("%d\n", getLength(new));
    // printf("%d\n", findFirst(3, new));
    // printf("%d\n", findLast(3, new));
    // enqueue(new, 3);
    dequeue(new);
    enqueue(new, 6);
    // insertAtIndex(new, -1, 4);
    merge(new, ano);
    // printf("%d\n", get(new, 7));
    // printf("%d\n", contains(new, 2));
    // removeIndex(new, 3);
    printf("%d\n", getFirst(new));
    printf("%d\n", getLast(new));
    to_string(new);
    LLNode* c = clone(new);
    to_string(c);
    clean(new);
    // pop(new);
    // pop(new);
    // pop(new);
    // pop(new);
    // printf("%d\n", new->prev->next->data);
}
