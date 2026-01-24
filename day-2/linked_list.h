
typedef struct Node {
    unsigned long value;
    struct Node *next;
} Node;

typedef struct List {
  Node* head; 
  Node* tail; 
  int count;  
} List;

void initList(List* list);

Node* initNode(unsigned long value);

void appendList(List* list, unsigned long value);

void printList(List* list);

int deleteHead(List* list);

void clearList(List* list);

int isinList(List* list, unsigned long value);