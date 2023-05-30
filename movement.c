#include "movement.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "map.h"
#include "io.h"
#include "LinkedList.h"
#include "map.h"
struct Node *head = NULL;

void move(char **map_array, int *player_row, int *player_col, int *box_row, int *box_col, int pull, char dir)
{

    /* Marking Crieteria: Using "Break " NOT on the switch case statement
            Have not used break(); anywhere except switch case

    */

    /* 1. Checks if the Player is near border
       2.Checks if the box is near the player and
       3. moves as required
        */
    switch (dir)
    {
    case 'w':

        if (!((map_array[*player_row - 1][*player_col] == '*') || (map_array[*player_row - 1][*player_col] == 'O')))

        {

            if ((isnear(*player_col, *player_row, *box_col, *box_row) == 'w'))
            {

                /*Marking Crieteria: Able to push the player around player  */
                if ((map_array[*box_row - 1][*box_col] != '*'))
                {
                    push(&head, createCoordinates(*box_row, *box_col));

                    *box_row = *box_row - 1;
                }
            }
            else if (((pull) && (isnear(*player_col, *player_row, *box_col, *box_row) == 's')))
            {
                push(&head, createCoordinates(*box_row, *box_col));

                *box_row = *box_row - 1;
            }

            *player_row = *player_row - 1;
            if ((*player_row == *box_row) && (*player_col == *box_col))
            {
                *player_row = *player_row + 1;
            }
        }

        break;

    case 'a':
        if (!((map_array[*player_row][*player_col - 1] == '*') || (map_array[*player_row][*player_col - 1] == 'O')))
        {
            if ((isnear(*player_col, *player_row, *box_col, *box_row) == 'a'))
            {
                /*Marking Crieteria: Able to push the player around player  */

                if ((map_array[*box_row][*box_col - 1] != '*'))
                {
                    push(&head, createCoordinates(*box_row, *box_col));

                    *box_col = *box_col - 1;
                }
            }

            else if (((pull) && (isnear(*player_col, *player_row, *box_col, *box_row) == 'd')))
            {
                push(&head, createCoordinates(*box_row, *box_col));

                *box_col = *box_col - 1;
            }
            *player_col = *player_col - 1;
            if ((*player_col == *box_col) && (*player_row == *box_row))
            {
                *player_col = *player_col + 1;
            }
        }

        break;

    case 's':
        if (!((map_array[*player_row + 1][*player_col] == '*') || (map_array[*player_row + 1][*player_col] == 'O')))
        {

            if (((isnear(*player_col, *player_row, *box_col, *box_row) == 's')))

            {
                /*Marking Crieteria: Able to push the player around player  */

                if ((map_array[*box_row + 1][*box_col] != '*'))
                {
                    push(&head, createCoordinates(*box_row, *box_col));

                    *box_row = *box_row + 1;
                }
            }

            else if (((pull) && (isnear(*player_col, *player_row, *box_col, *box_row) == 'w')))
            {
                push(&head, createCoordinates(*box_row, *box_col));

                *box_row = *box_row + 1;
            }

            *player_row = *player_row + 1;
            if ((*player_row == *box_row) && (*player_col == *box_col))
            {
                *player_row = *player_row - 1;
            }
        }
        break;

    case 'd':
        if (!((map_array[*player_row][*player_col + 1] == '*') || (map_array[*player_row][*player_col + 1] == 'O')))
        {
            if ((isnear(*player_col, *player_row, *box_col, *box_row) == 'd'))
            {
                /*Marking Crieteria: Able to push the player around player  */

                if ((map_array[*box_row][*box_col + 1] != '*'))
                {
                    push(&head, createCoordinates(*box_row, *box_col));

                    *box_col = *box_col + 1;
                }
            }

            else if (((pull) && (isnear(*player_col, *player_row, *box_col, *box_row) == 'a')))
            {
                push(&head, createCoordinates(*box_row, *box_col));

                *box_col = *box_col + 1;
            }
            *player_col = *player_col + 1;
            if ((*player_col == *box_col) && (*player_row == *box_row))
            {
                *player_col = *player_col - 1;
            }
        }

        break;

    default:
    {
        printf("Enter a Valid Char [w,a,s,d]");
    }
    }
}

char isnear(int player_col, int player_row, int box_col, int box_row)
{
    char dir;
    if ((player_row == box_row) && (player_col == box_col - 1))
    {

        dir = 'd';
    }

    if ((player_row == box_row) && (player_col == box_col + 1))

    {

        dir = 'a';
    }
    if ((player_row == box_row - 1) && (player_col == box_col))
    {

        dir = 's';
    }

    if ((player_row == box_row + 1) && (player_col == box_col))
    {
        dir = 'w';
    }
    return dir;
}

/* Checks if the game is won

    Marking Crieteria: Winning the game when the
    player moves the box to the goal
*/

int isWin(int box_col, int box_row, int goal_row, int goal_col)
{

    int win = 0;
    if ((box_row == goal_row) && (box_col == goal_col))
    {

        win = 1;
    }

    return win;
}

struct Coordinates createCoordinates(int x, int y)
{
    struct Coordinates coord;
    coord.x = x;
    coord.y = y;
    return coord;
}

void printall()
{
    printStack(head);
}

void track(char **map_array)
{
    int i = 0;
    printf("Coordinates Tracked:\n");
    struct Node *currentNode = head;
    while (currentNode != NULL)
    {
        i++;
        track_painter(map_array,&currentNode->data.x,&currentNode->data.y);
        printf("(%d, %d)\n", currentNode->data.x, currentNode->data.y);
        currentNode = currentNode->next;
    }
    printf("\n\n%d times\n\n", i);
}