# Conway's game of life
Description:<br>
This version of Canway's game of life dose not wrap around, but the rules are the same.<br>
a live cell with fewer than two live neighbors dies<br> 
a live cell with two or three live neighbors lives on to the next generation<br>
a live cell with more than three live neighbors dies<br>
a dead cell with exactly three live neighbors becomes a live cell

# To Play the Game:
Type *make* in the command line to compile the game, then type *./conway.out* to play it.
<br>
The first line of input is the row *space* column<br>
Example: > 5 4<br>
The second line is the number of times you want it to run<br>
Example: > 1<br>
The last input is the board, with no spaces (the board should match with the row and column numbers you put above)<br>
Example: <br>
xxxx<br>
xgrx<br>
xxgx<br>
xgrx<br>
xxxx
