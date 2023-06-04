#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeStack(Stack* stack) {
    stack->top = NULL;
}

int isStackEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, const GameState* game) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = createGameState(game->play_row, game->play_col, game->goal_row, game->goal_col, game->box_row, game->box_col, game->array, game->rows, game->col);
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack, int* play_row, int* play_col, int* goal_row, int* goal_col, int* box_row, int* box_col, char*** array, int* rows, int* col) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    Node* temp = stack->top;
    stack->top = stack->top->next;

    *play_row = temp->data->play_row;
    *play_col = temp->data->play_col;
    *goal_row = temp->data->goal_row;
    *goal_col = temp->data->goal_col;
    *box_row = temp->data->box_row;
    *box_col = temp->data->box_col;

    *rows = temp->data->rows;
    *col = temp->data->col;

    *array = (char**)malloc((*rows) * sizeof(char*));
    for (int i = 0; i < *rows; i++) {
        (*array)[i] = (char*)malloc((*col) * sizeof(char));
        memcpy((*array)[i], temp->data->array[i], (*col) * sizeof(char));
    }

    freeGameState(temp->data);
    free(temp);
}

GameState* createGameState(int play_row, int play_col, int goal_row, int goal_col, int box_row, int box_col, char** array, int rows, int col) {
    GameState* game = (GameState*)malloc(sizeof(GameState));
    game->play_row = play_row;
    game->play_col = play_col;
    game->goal_row = goal_row;
    game->goal_col = goal_col;
    game->box_row = box_row;
    game->box_col = box_col;

    game->rows = rows;
    game->col = col;

    game->array = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        game->array[i] = (char*)malloc(col * sizeof(char));
        memcpy(game->array[i], array[i], col * sizeof(char));
    }

    return game;
}

void freeGameState(GameState* game) {
    for (int i = 0; i < game->rows; i++) {
        free(game->array[i]);
    }
    free(game->array);
    free(game);
}

void freeStack(Stack* stack) {
    while (!isStackEmpty(stack)) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        freeGameState(temp->data);
        free(temp);
    }
}
