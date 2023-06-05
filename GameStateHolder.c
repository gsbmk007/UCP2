#include "GameStateHolder.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Marking Criteria : Assignment 2 Implement the generic linked list to
 store the relevant location information with appropriate struct. */

/* Initiates the struct which holds the coodinates and the array */
GameState *createGameState(int play_row, int play_col, int goal_row,
                           int goal_col, int box_row, int box_col, char **array,
                           int rows, int col) {
  int i = 0;
  GameState *game = (GameState *)malloc(sizeof(GameState));
  game->play_row = play_row;
  game->play_col = play_col;
  game->goal_row = goal_row;
  game->goal_col = goal_col;
  game->box_row = box_row;
  game->box_col = box_col;

  game->rows = rows;
  game->col = col;

  game->array = (char **)malloc(rows * sizeof(char *));
  for (i = 0; i < rows; i++) {
    game->array[i] = (char *)malloc(col * sizeof(char));
    memcpy(game->array[i], array[i], col * sizeof(char));
  }

  return game;
}

/* used to free the memory allocated */

void freeGameState(GameState *game) {
  int i = 0;
  for (i = 0; i < game->rows; i++) {
    free(game->array[i]);
  }
  free(game->array);
  free(game);
}

/* Used to push the game data into the stack whoch uses linkedlist from
 * LINKEDLIST.c */
void pushGameState(LinkedList *stack, int play_row, int play_col, int goal_row,
                   int goal_col, int box_row, int box_col, char **array,
                   int rows, int col) {
  /* Create a new GameState structure */
  GameState *game = createGameState(play_row, play_col, goal_row, goal_col,
                                    box_row, box_col, array, rows, col);

  /*      Push the GameState onto the stack
   */
  push(stack, game);
}

/* takes in  enviroinement variables and stack  */
int popGameState(LinkedList *stack, int *play_row, int *play_col, int *goal_row,
                 int *goal_col, int *box_row, int *box_col, char ***array,
                 int *rows, int *col) {
  GameState *game;
  int i = 0;
  pop(stack, (void **)&game);

  if (game == NULL) {
    printf("Stack is empty.\n");
    return 0;
  }

  *play_row = game->play_row;
  *play_col = game->play_col;
  *goal_row = game->goal_row;
  *goal_col = game->goal_col;
  *box_row = game->box_row;
  *box_col = game->box_col;

  *rows = game->rows;
  *col = game->col;

  *array = (char **)malloc((*rows) * sizeof(char *));
  for (i = 0; i < *rows; i++) {
    (*array)[i] = (char *)malloc((*col) * sizeof(char));
    memcpy((*array)[i], game->array[i], (*col) * sizeof(char));
  }

  freeGameState(game);
  return 1;
}
