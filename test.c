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

void insertAtBeginning(struct Node** head, struct Coordinates data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("(%d, %d) -> ", current->data.x, current->data.y);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    struct Coordinates c1 = {3, 5};
    struct Coordinates c2 = {8, 2};
    struct Coordinates c3 = {1, 7};

    insertAtBeginning(&head, c1);
    insertAtBeginning(&head, c2);
    insertAtBeginning(&head, c3);

    printf("Linked List: ");
    printList(head);

    return 0;
}