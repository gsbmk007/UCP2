#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "map.h"
#include "helper_funcs.h"
#include "io.h"
#include "movement.h"
#include "LinkedList.h"

int main(int argc, char *argv[])

{

#ifdef PULL
    int pull = 1;
#else
    int pull = 0;
#endif

    /* Implemented pull feature
    Marking Criteria : Implement the PULL feature with the conditional compilation
  */

    FILE *file;

    char **map_array = NULL;
    char (*getchar)();
    char filename[] = "data.txt";
    file = fopen(filename, "r");
    int log = 0, map_row = 0, map_col = 0, player_row = 0, player_col = 0, goal_row = 0, goal_col = 0, box_row = 0, box_col = 0, object_row = 0, object_col = 0, tempx = 0, tempy = 0;
    char tempc = '\0';
    printf("Fabric");
    printf("Creating Fabric %d", fscanf(file, "%d %d", &map_row, &map_col));







        /* Declared Variables requiredclear

            They are not global variables
            they are accessable only to the main function
                Marking Criteria : Using global variables
             */
        getchar = &get_input;

    initRandon();

    /* Creating and allocating 2d array using Malloc
    Marking Criteria : Proper memory allocation for the 2D map array.  */

    map_array = create_2d_array(map_array, map_row + 2, map_col + 2);
    printf("Created 2d array");

    create_fabric(map_array, map_row + 2, map_col + 2);

    while (fscanf(file, "%d %d %c", &tempx, &tempy, &tempc) != -1)

    {
        if (tempc == 'B')
        {
            box_row = tempx;
            box_col = tempy;
            printf("%c: %d,%d\n\n", tempc, tempx, tempy);
        }
        else if (tempc == 'P')
        {
            player_row = tempx;
            player_col = tempy;
            printf("%c: %d,%d\n\n", tempc, tempx, tempy);
        }
        else if (tempc == 'G')
        {
            goal_row = tempx;
            goal_col = tempy;
            printf("%c: %d,%d\n\n", tempc, tempx, tempy);
        }
        /* Cehcks if the input is correct

  if (map_row < 5 || map_col < 5 || ((player_row < 0) || (player_row > map_row)) || ((player_col < 0) || (player_col > map_col)) || ((goal_col < 0) || (goal_col > map_col)) || ((goal_row < 0) || (goal_row > map_row)))
    {
        printf("Error: Invalid argument values \n  1.Should be non-negative integers \n  2.The minimum Size is 5 X 5\n  3.Goal and plater Coordinates should be within the Map range ");

        return 1;

        /*  Marking Criteria : Not using exit();
    }

    if (argc != 7)
    {
        printf("Error: Incorrect number of arguments. Usage: ./box <map_row> <map_col> <player_row> <player_col> <goal_row> <goal_col>\n");
        return 1;
        /*  Marking Criteria : Not using exit();
    }
*/
        printf("\n\nTem px: %d, tempy: %d\n %c\n\n", tempx, tempy, tempc);

        create_players(map_array, tempx, tempy, tempc);
    }
    /* Drawing map */

    /* Randomly initialising box location
    Marking Criteria : Randomly initialize the box
    loaction correctly everytime the program starts  */

    /* create_objects(map_array, map_row, map_col, player_row, player_col, goal_row, goal_col, &box_row, &box_col);
     */
    /* Game LOOP is on until won

    Marking Criteria : Clears screen - Re-Prints the map on every action

     */
    while (!isWin(goal_col, goal_row, box_row, box_col))

    {
        clear_screen();

        print_map(map_array, map_row, map_col, 0);

        /* Removes the players from arrya to avoid do
       char */
        remove_players(map_array, player_row, player_col, goal_row, goal_col, box_row, box_col);
        /* Marking Criteria : Able to Move the player with keyboard input */
         move(map_array, &player_row, &player_col, &box_row, &box_col, pull, (*getchar)());
       
        /* Used  Pointer (*getchar) */

        /* Places the players on the map */
        plot_players(map_array, player_row, player_col, goal_row, goal_col, box_row, box_col);
    }
    clear_screen();

    print_map(map_array, map_row, map_col, 1);

    printf("Congratulations You have won The Game \n");
track(map_array);
    /* ReUsing pull varibale to save memory used  */

    /* Clearing memory */

    for (pull = 0; pull < map_row + 2; pull++)
    {
        free(map_array[pull]);
    }
    free(map_array);

    return 1;

    /* Debug code  */
    /* printf("Getchar :%p \n map_row: %p\n map_col: %p\nplayer_row: %p\nplayer_col: %p\ngoal_row: %p\ngoal_col: %p\nbox_row: %p\n box_col: %p\n",getchar,&map_row, &map_col, &player_row, &player_col, &goal_row, &goal_col, &box_row, &box_col);
     */
}
