#include <stdlib.h>
#include "board.h"
#include <stdio.h>
#include <stdbool.h>
Board *bptr;
Board b;
Board* update_board(Board *bptr) {
	int size = bptr->nrows*bptr->ncols;
	char *board = bptr->grid;
	int gcount=0;
	int rcount=0;
	char *updatingboard;
	updatingboard = (char *) malloc(size*sizeof(char));
	for (int i=0; i<=size; i++) {
		updatingboard[i] = board[i];	
	}	

	char oneround[8];  
//	printf("updating board %s\n", updatingboard);
	int rows = 0; // no wraping
	int cols = 0;	
	int count=0;
	int countg=0;
	int countr=0;
	for (int i=0; i<=size; i++) { // go though the board and update it
		if (i<bptr->ncols-1 && cols != 0) { // first row
			// not wraping inner top row
			//printf("times %d col%d\n", i, cols);
			//printf("stuff %c\n", board[i+(size-4)]);	
			if (board[i+1] == 'g') {
				oneround[0] = 'g';
			}	
			if (board[i+1] == 'r') {
				oneround[0] = 'r';
			}
			if (board[i+1] == 'x') {
				oneround[0] = 'x';
			}

			if (board[i+(bptr->ncols-1)] == 'g') { // 3
				oneround[1] = 'g';	
			} 
			if (board[i+(bptr->ncols-1)] == 'r') {
				oneround[1] = 'r';
			}
			if (board[i+(bptr->ncols-1)] == 'x') {
				oneround[1] = 'x';
			}	

			if (board[i-1] == 'g') {
				oneround[2] = 'g';
			}
			if (board[i-1] == 'r') {
				oneround[2] = 'r';
			}
			if (board[i-1] == 'x') {
				oneround[2] = 'x';
			}	

			if (board[i+bptr->ncols] == 'g') { // 4
				oneround[3] = 'g';
			}
			if (board[i+bptr->ncols] == 'r') {
				oneround[3] = 'r';
			}
			if (board[i+bptr->ncols] == 'x') {
				oneround[3] = 'x';
			}

			if (board[i+(bptr->ncols+1)] == 'g') { // 5
				oneround[4] = 'g';	
			}	
			if (board[i+(bptr->ncols+1)] == 'r') {
				oneround[4] = 'r';
			}	
			if (board[i+(bptr->ncols+1)] == 'x') {
				oneround[4] = 'x';
			}
			
			for (int a=0; a<=7; a++) {
				//printf("top oneround[%d] %c\n", a, oneround[a]);
				if (oneround[a] == 'g' || oneround[a] == 'r') {
					count ++;
				}
				if (oneround[a] == 'g') {
					countg ++;
				}
				if (oneround[a] == 'r') {
					countr ++;
				}	
			}	
			//if (count > 3 || count < 2) {
				//if (board[i] == 'g' || board[i] == 'r') {
					//updatingboard[i] = 'x';
				//}	
		//	}	
			if (count == 3 && board[i] == 'x' && countg > countr) {
				//printf("help");
				updatingboard[i] = 'g';
			}	
			if (count == 3 && board[i] == 'x' && countr > countg) {
				updatingboard[i] = 'r';
				count = 0;
				countg = 0;
				countr = 0;
			}
			if (count == 2 || count == 3) {
				count = 0;
				countr = 0;
				countg = 0;
			}	
		}	

		if (i >= (size-bptr->ncols)+1 && i < (size-1)) { //bottom row
			if (board[i+1] == 'g') {
				oneround[0] = 'g';
			}	
			if (board[i+1] == 'r') {
				oneround[0] = 'r';
			}
			if (board[i+1] == 'x') {
				oneround[0] = 'x';
			}	

			if (board[i-1] == 'g') {
				oneround[1] = 'g';
			}
			if (board[i-1] == 'r') {
				oneround[1] = 'r';
			}
			if (board[i-1] == 'x') {
				oneround[1] = 'x';
			}	

			if (board[i-(bptr->ncols+1)] == 'g') {  // 5
				oneround[2] ='g';
			}	
			if (board[i-(bptr->ncols+1)] == 'r') {
				oneround[2] = 'r';
			}
			if (board[i-(bptr->ncols+1)] == 'x') {
				oneround[2] = 'x';
			}	
			
			if (board[i-bptr->ncols] == 'g') {  // 4
				oneround[3]	= 'g';
			}
			if (board[i-bptr->ncols] == 'r') {
				oneround[3] = 'r';
			}
			if (board[i-bptr->ncols] == 'x') {
				oneround[3] = 'x';
			}	

			if (board[i-(bptr->ncols-1)] == 'g') {  // 3
				oneround[4] = 'g';
			}	
			if (board[i-(bptr->ncols-1)] == 'r') {
				oneround[4] = 'r';
			}
			if (board[i-(bptr->ncols-1)] == 'x') {
				oneround[4] = 'x';
			}
			
			for (int b=0; b<=7; b++) {
				if (oneround[b] == 'g' || oneround[b] == 'r') {
					count ++;
				}
				if (oneround[b] == 'g') {
					countg ++;
				}
				if (oneround[b] == 'r') {
					countr ++;
				}
			}	
			if (count == 3 && board[i] == 'x' && countg > countr) {
				updatingboard[i] = 'g';
			}	
			if (count == 3 && board[i] == 'x' && countr > countg) {
				updatingboard[i] = 'r';
				count = 0;
				countg = 0;
				countr = 0;
			}
			if (count == 2 || count == 3) {
				count = 0;
				countr = 0;
				countg = 0;
			}	
			
		}	
		//printf("rows %d\n", rows);

		if (cols == bptr->ncols-1) { // left side non wraping   3
// this one takes in the corners
			//printf("in rows %d\n", rows);
			//printf("times %d col%d\n", i, cols);
			//printf("stuff %c\n", board[i+(size-4)]);	
			if (board[i-4] == 'g') {
				oneround[0] = 'g';
			}	
			if (board[i-4] == 'r')	{
				oneround[0] = 'r';
			}		
			if (board[i-4] == 'x') {	
				oneround[0] = 'x';
			}		

			if (board[i-5] == 'g') {
				oneround[1] = 'g';
			}	
			if (board[i-5] == 'r')	{
				oneround[1] = 'r';
			}		
			if (board[i-5] == 'x')	{	
				oneround[1] = 'x';
			}

			if (board[i-1] == 'g') {
				oneround[2] = 'g';
			}	
			if (board[i-1] == 'r')	{
				oneround[2] = 'r';
			}
			if (board[i-1] == 'x') {	
				oneround[2] = 'x';
			}		

			if (board[i+3] == 'g') {
				oneround[3] = 'g';
			}	
			if (board[i+3] == 'r')	{
				oneround[3] = 'r';
			}
			if (board[i+3] == 'x')	{	
				oneround[3] = 'x';
			}		

			if (board[i+4] == 'g') {
				oneround[4] = 'g';
			}	
			if (board[i+4] == 'r')	{
				oneround[4] = 'r';
			}
			if (board[i+4] == 'x')	{	
				oneround[4] = 'x';
			}	
		
			for (int j=0; j<=7; j++) {	
				//printf("left oneround[%d] %c\n", j, oneround[j]);
				if (oneround[j] == 'g' || oneround[j] == 'r') {
					count ++;
				}
				if (oneround[j] == 'g') {	
					countg ++;
				}
				if (oneround[j] == 'r') {
					countr ++;
				}	
			}	
			if (count > 3 || count < 2) { 
				if (board[i] == 'g' || board[i] == 'r') {
					updatingboard[i] = 'x';
				}	
			}
			if (count == 3 && board[i] == 'x' && countg > countr) {
				updatingboard[i] = 'g';
			}
			 if (count == 3 && board[i] == 'x' && countr > countg) {
				updatingboard[i] = 'r';
				count=0;
				countg=0;
				countr=0;		
			}	
			if (count == 2 || count == 3) {
				count = 0;
				countr = 0;
				countg = 0;
			}	
			cols = 0;
			rows ++;
			//printf("rows %d cols = %d\n", rows, cols);	
		}	
// end of col 3		
		else if (cols == 0) {
			cols ++;
			//not wrapping	
			if (board[i+1] == 'x') { 
				oneround[0] = 'x';
			}
			if (board[i-bptr->ncols] == 'x') {
				oneround[1] = 'x';
			}
			if (board[i-(bptr->ncols-1)] == 'x') {
				oneround[2] = 'x';
			}
			if (board[i+(bptr->ncols)] == 'x') {
				oneround[3] = 'x';
			}
			if (board[i+(bptr->ncols+1)] == 'g') {
				oneround[4] = 'g';
			}	

		}	
// end of col 0		
		//if (i == size-bptr->ncols) { // fix later    16
		//	break;
		//}	
// end of last row
		if (board[i+1]) {
			if (board[i+1] == 'g') {
				oneround[0] = 'g';
			}
			else if (board[i+1] == 'r') {
				oneround[0] = 'r';
			}
			else {
				oneround[0] = 'x';
			}	
		//	printf("oneround %c\n", oneround[0]);
		}		
		if (board[i-1]) {
			if (board[i-1] == 'g') {
				oneround[1] ='g';
			}
			else if (board[i-1] == 'r') {
				oneround[1]	= 'r';
			}
			else {
				oneround[1]	= 'x';
			}	
		} 
		if (board[i-4]) {
			if (board[i-4] == 'g') {
				oneround[2] = 'g';
			}
			else if (board[i-4] == 'r') {
				oneround[2] = 'r';
			}	
			else {
				oneround[2] = 'x';
			}	
		}
		if (board[i-5]) {
			if (board[i-5] == 'g') {
				oneround[3] = 'g';
			}	
			else if (board[i-5] == 'r') {
				oneround[3] = 'r';
			}
			else {
				oneround[3] = 'x';
			}	
		}	
		if (board[i-3]) {
			if (board[i-3] == 'g') {
				oneround[4] = 'g';
			}
			else if (board[i-3] == 'r') {
				oneround[4] = 'r';
			}
			else {
				oneround[4] = 'x';	
			}
		}
		if (board[i+3]) {
			if (board[i+3] == 'g') {
				oneround[5] = 'g';
			}
			else if (board[i+3] == 'r') {
				oneround[5] = 'r';
			}
			else {
				oneround[5] = 'x';	
			}	
		}
		if (board[i+4]) {
			if (board[i+4] == 'g') {
				oneround[6] = 'g';
			}
			else if (board[i+4] == 'r') {
				oneround[6] = 'r';
			}
			else {
				oneround[6] = 'x';
			}	
		}
		if (board[i+5]) {
			if (board[i+5] == 'g') {
				oneround[7] = 'g';
			}
			else if (board[i+5] == 'r') {
				oneround[7] = 'r';
			}
			else { 
				oneround[7] = 'x';
			}	
			cols ++;
			for (int r=0; r<=7; r++) {
//				printf("oneround[%d] %c\n", r, oneround[r]);
				if (oneround[r] == 'g' || oneround[r] == 'r') {
					count ++;
				}	
				if (oneround[r] == 'g') {
					countg ++;
				}
				if (oneround[r] == 'r') {
					countr ++; 
				}	
			}	
		}		
		if (count > 3 || count < 2) { 
				//printf("count out %d\n", count);
				if (count > 3 && (count != 0 || count != bptr->ncols-1)) {
					//printf("hit\n");	
					updatingboard[i] = 'x';
					count = 0;
					countg = 0;
					countr = 0;
				}	
				if (count < 2) {
					count = 0;
				}		
		}
//		if (count == 3 && board[i] == 'x' && countg > countr) {
			//		updatingboard[i] = 'g';
//				printf("new board g\n");
//		}
		if (count == 3 && board[i] == 'x' && countr > countg) {
			//		updatingboard[i] = 'r';
				count=0;
				countg=0;
				countr=0;
		}  	
		if (count == 2 || count == 3) {
				count=0;
				countr=0;
				countg=0;
		}					
	}
	for (int i=0; i<=size; i++) { // for printing
		if (updatingboard[i] == 'g') {
			gcount ++;
		}
		if (updatingboard[i] == 'r') {
			rcount ++;
		}
	}
	int rowcount = 0;
	int colcount = 0;
	if (bptr->time == 1) {
		printf("\nThe board after %d time:\n", bptr->time);
	}
	printf("\nThe board after %d times:\n", bptr->time);
	for (int i=0; i<=size; i++) {
		//printf("ncols: %d\n", colcount);
		//printf("%c", updatingboard[i]);
		if (colcount != bptr->ncols) {
			colcount++;
			printf("%c", updatingboard[i]);
		}
		if (colcount == bptr->ncols) {
			rowcount++;
			//printf("%c", updatingboard[i]);
			colcount = 0;
			printf("\n");
		}
		if (rowcount == bptr->nrows) {
			//col_count++;
			//printf("%c", updatingboard[i]);
			rowcount = 1;
			printf("\n");
			//break;
		}
	}
	printf("updating board %s\n", updatingboard);
	printf("green: %d, red: %d\n", gcount, rcount);
//	bptr->grid = updatingboard;
	free(bptr->grid);
	free(bptr);
	free(updatingboard);
	return bptr;	
}		
