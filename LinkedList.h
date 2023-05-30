#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct Coordinates {
    int x;
    int y;
};

struct Node {
    struct Coordinates data;
    struct Node* next;
};

struct Node* createNode(struct Coordinates data);
void push(struct Node** head, struct Coordinates data);
void pop(struct Node** head);
struct Coordinates peek(struct Node* head);
void printStack(struct Node* head);

#endif /* LINKEDLIST_H */
