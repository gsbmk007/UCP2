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

struct Node* createNode(struct Coordinates data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** head, struct Coordinates data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void pop(struct Node** head) {
    if (*head == NULL) {
        printf("Stack underflow\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

struct Coordinates peek(struct Node* head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        struct Coordinates emptyCoord = {0, 0};
        return emptyCoord;
    }
    return head->data;
}

void printStack(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("(%d, %d)\n", current->data.x, current->data.y);
        current = current->next;
    }
}