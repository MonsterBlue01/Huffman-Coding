#include <stdio.h>
#include <stdlib.h>

#include "ht.h"

entry* initialize() {
    int index = 0;
    entry* e = (entry *)malloc(sizeof(entry));
    e->index = index;
    e->linkedlist = (ll *)malloc(sizeof(ll));
    e->linkedlist->Oindex = index++;
    entry* tmp = e;
    while (index < 200) {
        while (tmp->down != NULL) {
            tmp = tmp->down;
        }
        tmp->down = (entry *)malloc(sizeof(entry));
        tmp->down->linkedlist = (ll *)malloc(sizeof(ll));
        tmp->down->linkedlist->Oindex = index;
        tmp->down->up = tmp;
        tmp->down->index = index++;
    }
    return e;
}

void clean(entry* e) {
    while (e->up != NULL) {
        e = e->up;
    }
    while (e != NULL) {
        entry* tmp = e;
        free(tmp->linkedlist);
        free(tmp);
        e = e->down;
    }
}

int main() {
    entry* e = initialize();
    while (e->down != NULL) {
        printf("e->index: %d\n", e->index);
        printf("e->linkedlist->Oindex: %d\n", e->linkedlist->Oindex);
        e = e->down;
    }
    printf("e->index: %d\n", e->index);
    printf("e->linkedlist->Oindex: %d\n", e->linkedlist->Oindex);

    while (e->up != NULL) {
        printf("e->index: %d\n", e->index);
        printf("e->linkedlist->Oindex: %d\n", e->linkedlist->Oindex);
        e = e->up;
    }

    printf("e->index: %d\n", e->index);
    printf("e->linkedlist->Oindex: %d\n", e->linkedlist->Oindex);
    
    clean(e);
}
