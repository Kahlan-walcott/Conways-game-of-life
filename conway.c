#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include <stdbool.h>
int main(void) {
    Board b;
    Board *bptr;
    int end = EOF + 1;
    int ends;
    char stackboard;
    int green = 0;
    int red = 0;
    // input the r and c with spaces
    // input times it runs
    // input the board
    scanf("%d %d", &b.nrows, &b.ncols); // getting the first line input
    int boardsize = b.nrows * b.ncols;
    scanf("%d", &b.time);
    while (end != EOF) {
        if (b.nrows != 0) {
            bptr = (Board *)malloc(boardsize * sizeof(Board));
            bptr->grid = (char *)malloc(boardsize * sizeof(char));
            bptr->nrows = b.nrows;
            bptr->ncols = b.ncols;
            bptr->time = b.time;
        }
        // option 1
            for (int i = 0; i <= boardsize; i++) {
                scanf("%c", &stackboard);
                if (stackboard == ' ') {
                    i--;
            }
            if (stackboard != ' ') {
                * (bptr->grid + i) = stackboard;
            }
            if (stackboard == '\n' && i != boardsize) {
                i--;   
            }
        }
        end = scanf("%d", &ends);
    }
    for (int j = 0; j <= boardsize; j++) {
        if (b.time == 0 && *(bptr->grid + j) == 'g') {
            green++;
        }
        if (b.time == 0 && *(bptr->grid + j) == 'r') {
            red++;    
        } 
    }
    if (b.time == 0) {
        printf("green: %d, red: %d\n", green, red);
        free(bptr->grid);
        free(bptr);
    }
    else if (b.time != 0) {
        bptr = update_board(bptr);
    }
    return 0;
}
