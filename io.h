#ifndef io_h
#define io_h

void print_map(char **map_array, struct Node *head, int map_row, int map_col, int win);
void clear_screen();
void disableBUffer();
void enableBuffer();
char get_input();

#endif
