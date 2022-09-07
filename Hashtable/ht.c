#include <stdio.h>
#include <stdlib.h>

#include "ht.h"

entry* initialize() {
    int index = 0;
    entry* e = (entry *)malloc(sizeof(entry));
    e->index = index;
    e->linkedlist = (ll *)malloc(sizeof(ll));
    e->linkedlist->content = "\0";
    e->linkedlist->Oindex = index++;
    entry* tmp = e;
    while (index < 200) {
        while (tmp->down != NULL) {
            tmp = tmp->down;
        }
        tmp->down = (entry *)malloc(sizeof(entry));
        tmp->down->linkedlist = (ll *)malloc(sizeof(ll));
        tmp->down->linkedlist->content = "\0";
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
    push(e->linkedlist, "apple", e->index);
    push(e->down->linkedlist, "cat", e->index);                             // Check push
    push(e->linkedlist, "bear", e->index);
    while (e->down != NULL) {
        printf("e->index: %d\n", e->index);
        printf("e->linkedlist->Oindex: %d\n", e->linkedlist->Oindex);
        e = e->down;
    }
    printf("e->index: %d\n", e->index);
    printf("e->linkedlist->Oindex: %d\n", e->linkedlist->Oindex);
                                                                            // Test cases for entry
    while (e->up != NULL) {
        printf("e->index: %d\n", e->index);
        printf("e->linkedlist->Oindex: %d\n", e->linkedlist->Oindex);
        e = e->up;
    }

    printf("e->index: %d\n", e->index);
    printf("e->linkedlist->Oindex: %d\n", e->linkedlist->Oindex);

    // printf("Check push: %s (first)\n", e->linkedlist->content);
    // printf("Check push: %s (second)\n", e->linkedlist->next->content);   // Used to check if push in "linkedlist" works
    // printf("Check push: %s (last)\n", e->down->linkedlist->content);

    // ll* linkedlist = (ll *)malloc(sizeof(ll));
    // if ((linkedlist->prev == NULL) && (linkedlist->next == NULL)) {
    //     printf("It's null.\n");
    // }

    // char* out = pop(e->linkedlist);
    // printf("First: %s\n", e->linkedlist->content);                       // Used to check pop function
    // printf("Output: %s\n", out);
    // printf("Second: %s\n", e->linkedlist->next->content);
    
    clean(e);
}
