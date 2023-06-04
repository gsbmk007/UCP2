#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct GameState {
    int play_row;
    int play_col;
    int goal_row;
    int goal_col;
    int box_row;
    int box_col;
    char** array;
    int rows;
    int col;
} GameState;

typedef struct Node {
    GameState* data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initializeStack(Stack* stack);
int isStackEmpty(Stack* stack);
void push(Stack* stack, const GameState* game);
void pop(Stack* stack, int* play_row, int* play_col, int* goal_row, int* goal_col, int* box_row, int* box_col, char*** array, int* rows, int* col);
GameState* createGameState(int play_row, int play_col, int goal_row, int goal_col, int box_row, int box_col, char** array, int rows, int col);
void freeGameState(GameState* game);
void freeStack(Stack* stack);

#endif  /* LINKEDLIST_H */
