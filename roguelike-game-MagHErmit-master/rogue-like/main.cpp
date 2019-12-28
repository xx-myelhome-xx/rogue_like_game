#include <curses.h>
#include "Map.h"
#include "Game.h"


int main() {
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	clear();
	
	Map m;
	Game g(m);

	g.GameLoop();
	endwin();

	return 0;
}