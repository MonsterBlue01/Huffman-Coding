#include <stdio.h>
#include <stdlib.h>

#include "ht.h"

entry* pushEntry(entry* e) {
    if (e == NULL) {
        e = (entry *)malloc(sizeof(entry));
        e->linkedlist = (ll *)malloc(sizeof(ll));
        e->index = 0;
    } else {
        entry* tmp = e;
        while (tmp->down != NULL) {
            tmp = tmp->down;
        }
        tmp->down = (entry *)malloc(sizeof(entry));
        tmp->down->linkedlist = (ll *)malloc(sizeof(ll));
        tmp->down->index = tmp->index + 1;
    }
    return e;
}

int main() {
    entry* e = NULL;
    e = pushEntry(e);
    e = pushEntry(e);
    e = pushEntry(e);
    printf("%d\n", e->down->down->index);
}
