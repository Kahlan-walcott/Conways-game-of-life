#ifndef BOARD_H
#define BOARD_H

typedef struct Board {
    char *grid;
    int nrows;
    int ncols;
    int time;
} Board;

Board* update_board(Board *);

#endif