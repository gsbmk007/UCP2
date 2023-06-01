#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<stdio.h>

// Generic Node structure
typedef struct Node {
    void* data;
    struct Node* next;
} Node;

// Generic Linked List structure
typedef struct {
    Node* head;
} LinkedList;

// Create a new Node with given data
Node* createNode(void* data);

// Insert a Node at the beginning of the Linked List
void insertNode(LinkedList* list, void* data);

// Display the Linked List
void displayLinkedList(LinkedList* list, void (*displayFunction)(void*));

// Free the Linked List
void freeLinkedList(LinkedList* list, void (*freeFunction)(void*));

// Display function for a 2D array
void display2DArray(void* data);

// Free function for a 2D array
void free2DArray(void* data);

// Stack data structure using the LinkedList
typedef struct {
    LinkedList list;
} Stack;

// Push an element onto the stack
void push(Stack* stack, void* data, int size) ;

// Pop an element from the stack
void* pop(Stack* stack);

#endif /* LINKEDLIST_H */
