#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ll.h"

void push(ll* li, char* word, int num) {
    if (strcmp(li->content, "\0") == 0) {
        li->content = word;
        li->Iindex = 0;
        li->Oindex = num;
    } else {
        ll* tmp = li;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = (ll *)malloc(sizeof(ll));
        tmp->next->prev = tmp;
        tmp->next->Oindex = tmp->Oindex;
        tmp->next->Iindex = tmp->Iindex + 1;
        tmp->next->content = word;
    }
}

char* pop(ll* li) {
    if (li->next == NULL) {
        char* tmp = li->content;
        li->content = "\0";
        return tmp;
    } else {
        ll* tmp = li;
        while (tmp->next->next != NULL) {
            tmp = tmp->next;
        }
        char* tmp2 = tmp->next->content;
        free(tmp->next);
        tmp->next = NULL;
        return tmp2;
    }
}   
