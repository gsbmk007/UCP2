#ifndef GAMESTATEHOLDER_H
#define GAMESTATEHOLDER_H

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int play_row;
  int play_col;
  int goal_row;
  int goal_col;
  int box_row;
  int box_col;
  char **array;
  int rows;
  int col;
} GameState;

GameState *createGameState(int play_row, int play_col, int goal_row,
                           int goal_col, int box_row, int box_col, char **array,
                           int rows, int col);
void freeGameState(GameState *game);
void pushGameState(LinkedList *stack, int play_row, int play_col, int goal_row,
                   int goal_col, int box_row, int box_col, char **array,
                   int rows, int col);
int popGameState(LinkedList *stack, int *play_row, int *play_col, int *goal_row,
                 int *goal_col, int *box_row, int *box_col, char ***array,
                 int *rows, int *col);

#endif /* GAMESTATEHOLDER_H */
