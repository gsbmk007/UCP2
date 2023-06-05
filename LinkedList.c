#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/* Marking Criteria : Assignment 2 Implement the generic linked list to
 store the relevant location information with appropriate struct. */
void initializeStack(LinkedList *stack) { stack->top = NULL; }

int isStackEmpty(LinkedList *stack) { return stack->top == NULL; }

void push(LinkedList *stack, void *data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = stack->top;
  stack->top = newNode;
}

void pop(LinkedList *stack, void **data) {
  Node *temp;
  if (isStackEmpty(stack)) {
    printf("Stack is empty.\n");
    return;
  }

  temp = stack->top;
  stack->top = stack->top->next;
  *data = temp->data;

  free(temp);
}

void freeStack(LinkedList *stack) {
  while (!isStackEmpty(stack)) {
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
  }
}
