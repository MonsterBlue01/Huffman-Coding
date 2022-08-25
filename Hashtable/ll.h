typedef struct ll {
    struct ll *prev;
    struct ll *next;
    char* content;
    int Oindex;
    int Iindex;
} ll;

ll* push(ll* li, char* word);

char* pop(ll* li);
