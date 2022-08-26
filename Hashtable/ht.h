#include "ll.h"

typedef struct entry {
    ll* linkedlist;
    struct entry* down;
    struct entry* up;
    int index;
} entry;

entry* pushEntry(entry* e);
