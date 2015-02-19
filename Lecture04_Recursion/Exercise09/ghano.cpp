#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                  /*  for sleep()  */
#include <curses.h>
#include "LLToolkit.hpp"
#include "node.hpp"

#define BBLACK 1
#define WWHITE 2

void printBlock(int size, int max_size, int pole, int height, int type)
{
	color_set(type, NULL);
	mvaddnstr(max_size-height,1+pole*((max_size+1)*2)+(max_size-size),"-------------------------------------------------------------",2*size);
}

void printTower(int pole, int max_size, Node<int>* q) {
	int length = LLToolkit<int>::length(q);;
	for (int i = 1; i < length+1; ++i) {
		printBlock(q->info, max_size, pole, length-i, WWHITE);
		q = q->next;
		refresh();
	}
	printBlock(max_size, max_size, pole, -1, 3);
	refresh();
}

void moveBlock(int from, int to, int max_size, Node<int>** q, int sleep) {
	int length = LLToolkit<int>::length(q[from]);
	int size = q[from]->info;
	printBlock(size, max_size, from, length-1, BBLACK);
	LLToolkit<int>::headRemove(q[from]);
	LLToolkit<int>::headInsert(q[to], size);
	length = LLToolkit<int>::length(q[to]);
	printBlock(size, max_size, to, length-1, WWHITE);
	move(0,0);
	refresh();
	usleep(sleep);
}

void hanoi(int max_size, int from, int via , int to, int size, Node<int>** q,int sleep) {
        if ( size == 0 ) {
                return;
        }
        else {
                hanoi(max_size, from, to, via, size-1, q, sleep);
		moveBlock(from, to, max_size, q, sleep);
                hanoi(max_size, via, from, to, size-1, q, sleep);
        }
}

int main(int argc, char* argv[] ) {

	WINDOW * mainwin;
	Node<int>* q[3];
	int size = 4;
	int sleep = 500000;
	if (argc > 1) {
		size = atoi(argv[1]);
		if (size < 1) { size = 5; }
		if (argc > 2) {
			sleep = atoi(argv[2]);
		}
	}
        //int size = 10;
	q[0] = NULL;
        q[1] = NULL;
        q[2] = NULL;
        for (int i = size; i > 0 ; --i) {
                LLToolkit<int>::headInsert(q[0],i);
        }

	if ( (mainwin = initscr()) == NULL ) {
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);
	}

	start_color();

	if ( has_colors() && COLOR_PAIRS >= 2 ) {
		init_pair(1,  COLOR_BLACK,     COLOR_BLACK);
        	init_pair(2,  COLOR_WHITE,   COLOR_WHITE);	
        	init_pair(3,  COLOR_WHITE,   COLOR_BLACK);	

		printTower(0,size,q[0]);
		printTower(1,size,q[1]);
		printTower(2,size,q[2]);
		usleep(500);
		hanoi(size,0,1,2,size,q, sleep);

	}
	//Exit
	delwin(mainwin);
	endwin();
	refresh();
	return EXIT_SUCCESS;
}
