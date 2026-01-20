typedef struct Node {
    int num;
    struct Node *next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int count;

    bool (*cmp)(const void*, const void*);
    void (*print)(const void*);
} List;

Node *createNode(int num);

Node* initNode(void* num, size_t elem_size);

void freeNode(Node* node);

void initList(List* list, bool (*cmp)(const void*, const void*),
              void (*print)(const void*));

bool deleteHead(List* list);

void clearList(List* list);

void freeList(List* list);

void listPrepend(List* list, void* value, size_t elem_size);

void listAppend(List* list, void* value, size_t elem_size);

Node* listFind(List* list, void* value);