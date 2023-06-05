#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

typedef struct {
  Node *top;
} LinkedList;

void initializeStack(LinkedList *stack);
int isStackEmpty(LinkedList *stack);
void push(LinkedList *stack, void *data);
void pop(LinkedList *stack, void **data);
void freeStack(LinkedList *stack);

#endif
