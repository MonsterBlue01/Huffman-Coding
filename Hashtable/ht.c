#include <stdio.h>
#include <stdlib.h>

#include "ht.h"

entry* initialize() {
    int index = 0;
    entry* e = (entry *)malloc(sizeof(entry));
    e->index = index++;
    entry* tmp = e;
    while (index < 200) {
        while (tmp->down != NULL) {
            tmp = tmp->down;
        }
        tmp->down = (entry *)malloc(sizeof(entry));
        tmp->down->up = tmp;
        tmp->down->index = index++;
        printf("Index: %d\n", index);
    }
    return e;
}

int main() {
    entry* e = initialize();
    entry* tmp = e;
    while (tmp->down != NULL) {
        printf("Index down: %d\n", tmp->index);
        tmp = tmp->down;
    }
    while (tmp->up != NULL) {
        printf("Index up: %d\n", tmp->index);
        tmp = tmp->up;
    }
}
