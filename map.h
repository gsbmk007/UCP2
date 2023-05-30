#ifndef map_h
#define map_h

char **create_2d_array(char **map_array, int nrows, int ncols);
void create_fabric(char **map_array, int map_row, int map_col);
/* void create_objects(char **map_array, int map_row, int map_col, int player_row, int player_col, int goal_row, int goal_col, int *box_row, int *box_col);
*/void create_players(char **map_array,int tempx,int tempy,char tempc);

void plot_players(char **map_array,int player_row, int player_col, int goal_row, int goal_col, int box_row,int box_col);

void remove_players(char **map_array,int player_row, int player_col, int goal_row, int goal_col, int box_row,int box_col);
void path_tracker(char **map_array, int player_row,int player_col);

#endif
