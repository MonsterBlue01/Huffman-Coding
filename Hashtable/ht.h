typedef struct list {
    int key;                // key
    char* value;            // value
    struct list* next;      // conflict list
} list;

typedef struct hashtable {
    list* table;
} hashtable;

add(int key, char* value);

get(int key);

remove(int key);

getSize();

isEmpty();