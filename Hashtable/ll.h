typedef struct ll {
    struct ll *prev;
    struct ll *next;
    char* content;
} ll;

ll* push(ll* li, char* word);
