#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Coordinates{
  int x;
  int y;

};

struct CharData {
  char character;
};

enum DataType {
  COORDINATES,
  CHAR_DATA
};

struct Node {
  enum DataType data_type;
  void *data;
  struct Node *next;
};

void push(struct Node **head, enum DataType data_type, void *data);
void pop(struct Node **head);
void *peek(struct Node *head);
void printStack(struct Node *head);
struct Coordinates *createCoordinates(int x, int y);
struct CharData *createCharData(char character) ;


#endif /* LINKEDLIST_H */
