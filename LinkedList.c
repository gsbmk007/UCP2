#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void push(struct Node **head, enum DataType data_type, void *data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data_type = data_type;
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

void pop(struct Node **head) {
  if (*head == NULL) {
    printf("Stack underflow\n");
    return;
  }
  struct Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void *peek(struct Node *head) {
  if (head == NULL) {
    printf("Stack is empty\n");
    return NULL;
  }
  return head->data;
}

void printStack(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    if (current->data_type == COORDINATES) {
      struct Coordinates *coord = (struct Coordinates *)current->data;
      printf("Coordinates: (%d, %d)\n", coord->x, coord->y);
    } else if (current->data_type == CHAR_DATA) {
      struct CharData *charData = (struct CharData *)current->data;
      printf("Character: %c\n", charData->character);
    }
    current = current->next;
  }
}
struct Coordinates *createCoordinates(int x, int y)
       
{

  struct Coordinates *coord = (struct Coordinates *)malloc(sizeof(struct Coordinates));
  coord->x = x;
  coord->y = y;
  return coord;
};

struct CharData *createCharData(char character) {
  struct CharData *charData = (struct CharData *)malloc(sizeof(struct CharData));
  charData->character = character;
  return charData;
}
