#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

void initList(List* list) {
  list->head = NULL;
  list->tail = NULL;
  list->count = 0;
}

Node* initNode(unsigned long value) {
  Node* node = malloc(sizeof(Node)); 

  node->value = value; 

  node->next = NULL;
  return node;
}

void appendList(List* list, unsigned long value) {
  Node* tmp = initNode(value);
  if (list->count == 0) {
    list->head = tmp;
    list->tail = tmp;
  } else {
    list->tail->next = tmp;
    list->tail = tmp;
  }
  list->count++;
}

void printList(List* list){
   struct Node *p = list->head;
   printf("\n[");
   while(p != NULL) {
      printf(" %ld ",p->value);
      p = p->next;
   }
   printf("]");
}

int deleteHead(List* list) {
  if (list->count == 0) {
    return 0;
  }

  Node* newHead = list->head->next; // Store next
  free(list->head);       
  list->head = newHead;           
  list->count--;                  
  return 1;
}

void clearList(List* list) {
  while (deleteHead(list)) {
    continue;
  }
  list->head = NULL;
  list->tail = NULL;
  list->count = 0;
}

int isinList(List* list, unsigned long value) {
  if (list->count == 0) {
    return 0;
  }

  Node* tmp = list->head;

  while (tmp != NULL) {

    if (tmp->value == value) {
      return 1;
    }
    tmp = tmp->next;
  }
  return 0;
}
