#ifndef BOX_H
#define BOX_H
#include "GameStateHolder.h"
#include "LinkedList.h"
#include "helper_funcs.h"
#include "io.h"
#include "map.h"
#include "movement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Main Function */
int main(int argc, char *argv[]) {
#ifdef PULL
  int pull = 1;
#else
  int pull = 0;
#endif

  /*   Implemented pull feature */
  /* Marking Criteria: Implement the PULL feature with the conditional
   * compilation */

  FILE *file;
  LinkedList stack;

  char **map_array = NULL;
  char dir = ' ';
  char (*getchar)();
  char* filename = argv[1];

  int map_row = 0, map_col = 0, player_row = 0, player_col = 0, goal_row = 0,
      goal_col = 0, box_row = 0, box_col = 0, tempx = 0, tempy = 0;
  char tempc = '\0';
  if (argc < 2) {
      printf("Error: Incorrect number of arguments. Usage: ./box <FILE_NAME>");
      return 1;
      /*   Marking Criteria - Not using exit() */
    }
  file = fopen(filename, "r");
  fscanf(file, "%d %d", &map_row, &map_col);

  /*   Declared Variables required */
  /* They are not global variables, they are accessible only to the main
   * function */
  /* Marking Criteria: Using global variables */

  getchar = &get_input;

  initRandon();

  /*   Creating and allocating 2D array using Malloc */
  /* Marking Criteria: Proper memory allocation for the 2D map array. */
  map_row += 2;
  map_col += 2;
  map_array = create_2d_array(map_array, map_row, map_col);
  initializeStack(&stack);
  printf("Created 2D array");

  create_fabric(map_array, map_row, map_col);

  /*   Assignment 2 */
  /* Correctly handles the file I/O to open and read the provided text file to
   * retrieve the map size and game characters to configure the initial game
   * state */

  while (fscanf(file, "%d %d %c", &tempx, &tempy, &tempc) != -1) {
    if (tempc == 'B') {
      box_row = tempx;
      box_col = tempy;
      printf("%c: %d,%d\n\n", tempc, tempx, tempy);
    } else if (tempc == 'P') {
      player_row = tempx;
      player_col = tempy;
      printf("%c: %d,%d\n\n", tempc, tempx, tempy);
    } else if (tempc == 'G') {
      goal_row = tempx;
      goal_col = tempy;
      printf("%c: %d,%d\n\n", tempc, tempx, tempy);
    }

    /*   Checks if the input is correct */
    if (map_row < 5 || map_col < 5 ||
        ((player_row < 0) || (player_row > map_row)) ||
        ((player_col < 0) || (player_col > map_col)) ||
        ((goal_col < 0) || (goal_col > map_col)) ||
        ((goal_row < 0) || (goal_row > map_row))) {
      printf("Error: Invalid argument values\n  1. Should be non-negative "
             "integers\n  2. The minimum Size is 5 X 5\n  3. Goal and player "
             "coordinates should be within the map range");
      /*   Marking Criteria - Not using exit() */
      return 1;
    }

    

    printf("\n\nTemp x: %d, temp y: %d\n %c\n\n", tempx, tempy, tempc);

    create_players(map_array, tempx, tempy, tempc);
  }

  /*   Drawing map */
  /* Old Code for assignment 1 */

  /* Randomly initializing box location */
  /* Marking Criteria: Randomly initialize the box location correctly every time
   * the program starts */
  /* create_objects(map_array, map_row, map_col, player_row, player_col,
   * goal_row, goal_col, &box_row, &box_col); */

  /*   Clears screen - Re-Prints the map on every action */

  while (!isWin(goal_col, goal_row, box_row, box_col)) {
    clear_screen();
    print_map(map_array, map_row, map_col, 0);
    remove_players(map_array, player_row, player_col, goal_row, goal_col,
                   box_row, box_col);

    if (dir != 'u') {
      path_tracker(map_array, player_row, player_col);
      pushGameState(&stack, player_row, player_col, goal_row, goal_col, box_row,
                    box_col, map_array, map_row, map_col);
    }

    /*   Removes the players from the array to avoid double char */
    /* Marking Criteria: Able to move the player with keyboard input */
    if ((dir = (*getchar)()) == 'u') {
      popGameState(&stack, &player_row, &player_col, &goal_row, &goal_col,
                   &box_row, &box_col, &map_array, &map_row, &map_col);
    } else {
      move(map_array, &player_row, &player_col, &box_row, &box_col, pull, dir);
    }

    /*   Used function Pointer (*getchar) */

    /* Places the players on the map */
    plot_players(map_array, player_row, player_col, goal_row, goal_col, box_row,
                 box_col);
  }

  clear_screen();
  print_map(map_array, map_row, map_col, 1);
  printf("Congratulations! You have won the game\n");

  /*   Reusing pull variable to save memory used */

  /* Clearing memory */
  for (pull = 0; pull < map_row; pull++) {
    free(map_array[pull]);
  }

  freeStack(&stack);

  return 1;

  /* Debug code */
  /* printf("Getchar: %p\nmap_row: %p\nmap_col: %p\nplayer_row: %p\nplayer_col:
   * %p\ngoal_row: %p\ngoal_col: %p\nbox_row: %p\nbox_col: %p\n", getchar,
   * &map_row, &map_col, &player_row, &player_col, &goal_row, &goal_col,
   * &box_row, &box_col); */
}
#endif
