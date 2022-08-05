typedef struct list {
    int key;                            // key
    char* value;                        // value
    struct list* next;                  // conflict list
} list;

typedef struct hashtable {
    list* table;
} hashtable;

unsigned long hash(unsigned char *str);

add(int key, char* value);

get(int key);

remove(int key);

getSize();

isEmpty();
