
#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "helper_funcs.h"

char **create_2d_array(char **map_array,int map_row, int map_col)
{
    int i, j;

    /*     allocate memory for the array of row pointers
     */
    map_array = (char **)malloc(map_row * sizeof(char *));
    if (map_array == NULL)
    {
        /*         // handle allocation error
         */
        return NULL;
    }

    /*     allocate memory for each row
     */
    for (i = 0; i < map_row; i++)
    {
        map_array[i] = (char *)malloc(map_col * sizeof(char));
        if (map_array[i] == NULL)
        {
            /*             handle allocation error
             */
            for (j = 0; j < i; j++)
            {
                free(map_array[j]);
            }
            return NULL;
        }
    }

    /*     return the pointer to the 2D map_array
     */
    return map_array;
}

void create_fabric(char **map_array, int map_row, int map_cols)
{
    int i, j;
    for (i = 0; i < map_row; i++)
    {
        for (j = 0; j < map_cols; j++)
        {
            if (i == 0 || j == 0 || i == map_row - 1 || j == map_cols - 1)
            {
                map_array[i][j] = '*';
            }
            else
            {
                map_array[i][j] = ' ';
            }
        }
    }
}

void create_objects(char **map_array, int map_row, int map_col, int player_row, int player_col, int goal_row, int goal_col, int *box_row,int *box_col)
{
    int isset = 0;
    /*   created a while loop so that it keeps generting
       random coordinates if the coordinates are same as the player and the goal coordinates
   */
    while (!isset)
    {
    *box_row = randomUCP(2, map_row-1);
    *box_col = randomUCP(2, map_col - 1);
        if (!(((*box_row == goal_row) && (*box_col == goal_col)) || ((*box_row == player_row) && (*box_col == player_col))))
        {
            isset = 1;
        }
    }
    map_array[*box_row][*box_col] = 'B';
    map_array[player_row][player_col] = 'P';
    map_array[goal_row][goal_col] = 'G';
}



/* Function to add players to coordinates */
void plot_players(char **map_array,int player_row, int player_col, int goal_row, int goal_col, int box_row,int box_col){
            map_array[player_row][player_col] = 'P';
            map_array[goal_row][goal_col]='G';
             map_array[box_row][box_col] = 'B';

             if((player_row==goal_row)&&(player_col==goal_col)){
                                    map_array[goal_row][goal_col]='P';

             }
             if((box_row==goal_row)&&(box_col==goal_col)){
                                                    map_array[box_row][box_col]='G';


             }


}

/* Function to remove players from coordinates */

void remove_players(char **map_array,int player_row, int player_col, int goal_row, int goal_col, int box_row,int box_col){
            map_array[player_row][player_col] = ' ';
            map_array[goal_row][goal_col]=' ';
             map_array[box_row][box_col] = ' ';


}
