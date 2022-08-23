#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

ll* push(ll* li, char* word) {
    if (li == NULL) {
        li = (ll *)malloc(sizeof(ll));
        li->content = (char *)malloc(sizeof(char));
        li->content = word;
    } else {
        li->next = (ll *)malloc(sizeof(ll));
        li->next->content = (char *)malloc(sizeof(char));
        li->next->content = word;
    }
    return li;
}
