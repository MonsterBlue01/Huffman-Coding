struct LLNode {
	int data;
	struct LLNode *next;
    struct LLNode *prev;
};

typedef struct LLNode LLNode;

LLNode* createNew(int val);

int getLength(LLNode* node);

int findFirst(int element, LLNode* node);

int findLast(int element, LLNode* node);

void push(LLNode* node, int val);

void pop(LLNode* node);

void clean(LLNode* node);

void enqueue(LLNode* node, int val);

void dequeue(LLNode* node);

void to_string(LLNode* node);
