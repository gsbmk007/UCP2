

#ifndef movement_h
#define movement_h

void move(char **map_array, int *player_row, int *player_col, int *box_row, int *box_col, int pull, char dir);

char isnear(int player_col, int player_row, int goal_col, int goal_row);
int isWin(int goal_col, int goal_row, int box_row, int box_col);
struct Coordinates createCoordinates(int x, int y);

void printall();
void track(char **map_array);
#endif
