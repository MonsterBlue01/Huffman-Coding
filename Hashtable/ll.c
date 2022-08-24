#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

ll* push(ll* li, char* word) {
    if (li == NULL) {
        li = (ll *)malloc(sizeof(ll));
        li->content = word;
    } else {
        ll* tmp = li;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = (ll *)malloc(sizeof(ll));
        tmp->next->prev = tmp;
        tmp->next->content = word;
    }
    return li;
}

char* pop(ll* li) {
    ll* tmp = li;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    char* out = tmp->content;
    if (tmp->prev != NULL) {
        tmp->prev->next = NULL;
    }
    free(tmp);
    tmp = NULL;
    return out;
}
