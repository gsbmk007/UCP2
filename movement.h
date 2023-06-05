

#ifndef movement_h
#define movement_h

void move(char **map_array, int *player_row, int *player_col, int *goal_row,
          int *goal_col, int pull, char dir);

char isnear(int player_col, int player_row, int goal_col, int goal_row);
int isWin(int goal_col, int goal_row, int box_row, int box_col);

#endif
