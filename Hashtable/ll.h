typedef struct ll {
    struct ll *prev;
    struct ll *next;
    char* content;
    int Oindex;
    int Iindex;
} ll;

void push(ll* li, char* word, int num);

char* pop(ll* li);
