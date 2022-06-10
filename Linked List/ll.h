struct LLNode {
	int data;
	struct LLNode *next;
    struct LLNode *prev;
};

typedef struct LLNode LLNode;

LLNode* createNew(int val);
