#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generic Node structure
typedef struct Node {
  void *data;
  struct Node *next;
} Node;

// Generic Linked List structure
typedef struct {
  Node *head;
} LinkedList;

// Create a new Node with given data
Node *createNode(void *data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Insert a Node at the beginning of the Linked List
void insertNode(LinkedList *list, void *data) {
  Node *newNode = createNode(data);
  newNode->next = list->head;
  list->head = newNode;
}

// Display the Linked List
void displayLinkedList(LinkedList *list, void (*displayFunction)(void *)) {
  Node *temp = list->head;
  while (temp != NULL) {
    displayFunction(temp->data);
    temp = temp->next;
  }
}

// Free the Linked List
void freeLinkedList(LinkedList *list, void (*freeFunction)(void *)) {
  Node *temp;
  while (list->head != NULL) {
    temp = list->head;
    list->head = list->head->next;
    freeFunction(temp->data);
    free(temp);
  }
}

// Display function for a 2D array
void display2DArray(void *data,map_row,map_col) {
  char **map_array = (char **)data;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      printf("%c ", map_array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Free function for a 2D array
void free2DArray(void *data) {
  char **map_array = (char **)data;
  for (int i = 0; i < 3; i++) {
    free(map_array[i]);
  }
  free(map_array);
}

// Stack data structure using the LinkedList
typedef struct {
  LinkedList list;
} Stack;

// Push an element onto the stack
void push(Stack* stack, void* data, int size) {
    char** copy = (char**)malloc(size * sizeof(char*));
    if (copy == NULL) {
        printf("Memory allocation failed. Cannot push element.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        copy[i] = (char*)malloc((strlen(((char**)data)[i]) + 1) * sizeof(char));
        if (copy[i] == NULL) {
            printf("Memory allocation failed. Cannot push element.\n");
            for (int j = 0; j < i; j++) {
                free(copy[j]);
            }
            free(copy);
            return;
        }
        strcpy(copy[i], ((char**)data)[i]);
    }

    insertNode(&(stack->list), copy);
}


// Pop an element from the stack
void* pop(Stack* stack) {
    if (stack->list.head == NULL) {
        return NULL; // Stack is empty
    }

    Node* temp = stack->list.head;
    stack->list.head = stack->list.head->next;
    void* data = temp->data;
    free(temp);

    return data;
}
