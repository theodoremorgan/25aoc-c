// linked list of numbers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <list.h>

Node *createNode(int num) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->num = num;

    newNode->next = NULL;
    
    return newNode;
}

Node* initNode(void* num, size_t elem_size){
    Node* node = malloc(sizeof(Node));

    if (node==NULL) {
        exit(1);
    }

    memcpy(node->num, num, elem_size);

    node->next = NULL;
    return node;
}

void freeNode(Node* node) {
    if (node ==NULL) return;

    free(node->num);
    node->num = NULL;
    node-> next = NULL;

    free(node);
}

typedef struct {
    Node* head;
    Node* tail;
    int count;

    bool (*cmp)(const void*, const void*);
    void (*print)(const void*);
} List;

void initList(List* list, bool (*cmp)(const void*, const void*),
              void (*print)(const void*)) {
  list->head = NULL;
  list->tail = NULL;
  list->count = 0;
  list->cmp = cmp;
  list->print = print;
}

bool deleteHead(List* list) {
  if (list->count == 0) {
    return false;
  }

  Node* newHead = list->head->next; // Store next
  freeNode(list->head);             // Free node
  list->head = newHead;             // Update head
  list->count--;                    // Decrement count
  return true;
}

void clearList(List* list) {
  //Delete every node from head to tail
  while (deleteHead(list)) {
    continue;
  }
  list->head = NULL;
  list->tail = NULL;
  list->count = 0;
}

void freeList(List* list) {
  clearList(list);
  list->head = NULL;
  list->tail = NULL;
  list->count = 0;
  list->cmp = NULL;
  list->print = NULL;
}

void listPrepend(List* list, void* value, size_t elem_size) {
  Node* newNode = initNode(value, elem_size);
  if (list->count == 0) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    newNode->next = list->head;
    list->head = newNode;
  }
  list->count++;
}

void listAppend(List* list, void* value, size_t elem_size) {
  Node* newNode = initNode(value, elem_size);
  if (list->count == 0) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    list->tail->next = newNode;
    list->tail = newNode;
  }
  list->count++;
}

Node* listFind(List* list, void* value) {
  if (list->count == 0) {
    return NULL;
  }

  Node* tmp = list->head;

  while (!list->cmp(tmp->num, value)) {
    if (tmp->next == NULL) {
      return NULL;
      ;
    }
    tmp = tmp->next;
  }
  return tmp;
}