#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct Node {
    char** data;    // Pointer to the 2D char array
    int rows;       // Number of rows in the array
    struct Node* next;
};

// Function to push a copy of a 2D char array to the linked list
void push(struct Node** head, char** array, int rows) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Allocate memory for the new array
    char** newArray = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        newArray[i] = (char*)malloc(strlen(array[i]) + 1);
        strcpy(newArray[i], array[i]);
    }

    // Set the data and row size of the new node
    newNode->data = newArray;
    newNode->rows = rows;

    // Set the next pointer of the new node
    newNode->next = *head;

    // Update the head to point to the new node
    *head = newNode;
}

// Function to pop the top element from the linked list and copy it to a provided address
void pop(struct Node** head, char*** dest, int* destRows) {
    if (*head == NULL) {
        printf("Error: The linked list is empty.\n");
        return;
    }

    // Get the top node
    struct Node* top = *head;

    // Copy the data and row size to the destination
    *dest = top->data;
    *destRows = top->rows;

    // Update the head to point to the next node
    *head = top->next;

    // Free the memory of the top node
    for (int i = 0; i < top->rows; i++) {
        free(top->data[i]);
    }
    free(top->data);
    free(top);
}

// Function to print the elements in the linked list
void printList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        for (int i = 0; i < current->rows; i++) {
            printf("%s\n", current->data[i]);
        }
        printf("\n");
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        for (int i = 0; i < current->rows; i++) {
            free(current->data[i]);
        }
        free(current->data);

        struct Node* next = current->next;
        free(current);
        current = next;
    }
}

