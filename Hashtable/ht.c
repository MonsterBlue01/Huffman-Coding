#include <stdio.h>
#include <stdlib.h>

#include "ht.h"

int main() {
    ll* new = NULL;
    new = push(new, "apple");
    new = push(new, "bear");
    new = push(new, "cat");
    pop(new);
    pop(new);
    pop(new);
}

// Check memory leak
