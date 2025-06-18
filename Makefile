all: 
	gcc -Wall conway.c board.c -o conway.out
clean:
	rm conway.out
