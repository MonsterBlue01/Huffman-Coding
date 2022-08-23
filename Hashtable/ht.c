#include <stdio.h>
#include <stdlib.h>

#include "ht.h"

int main() {
    ll* new = NULL;
    new = push(new, "apple");
    new = push(new, "bear");
    printf("%s\n", new->next->content);
}
