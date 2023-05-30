#include "io.h"
#include <termios.h>
#include "stdio.h"
#include "stdlib.h"

char get_input()
{
    char ch;
    disableBUffer();
    scanf("%c", &ch);
    enableBuffer();
    return ch;
}

/* Marking Crieteria: Successfully disable the Echo and
Canonical temporarily so that the user does not need to
press the ”enter” key to issue command.*/
void disableBUffer()
{
    struct termios mode;
    tcgetattr(0, &mode);
    mode.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}

void enableBuffer()
{
    struct termios mode;
    tcgetattr(0, &mode);
    mode.c_lflag |= (ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}

void clear_screen()
{
    system("clear");
}

/* Printing the map and changing the background colours as rquired  */

void print_map(char **map_array, int map_row, int map_col, int win)
{
    int i, j;
    for (i = 0; i < map_row + 2; i++)
    {
        for (j = 0; j < map_col + 2; j++)
        {
            if (map_array[i][j] == 'G')
            {
                if (win)
                {
                    /* Changes to green */
                    printf("\033[42m");
                }
                else
                {
                    /* Changes to Red */
                    printf("\033[41m");
                }
            }
            
            
                printf("%c", map_array[i][j]);
                printf("\033[49m");
            
        }
        printf("\n");
    }

    printf("Move the box to the goal to win the game!\nPress W to move Up \nPress A to move left\nPress S to move down \nPress D to move right\n");
}
