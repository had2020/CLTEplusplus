#include <cstdio>
#include <ncurses.h>
#include <string>

// g++ -lncurses -o testing testing.cpp
// Compling with ncurses on c++ on arm

int main()
{
	initscr();			/* Start curses mode 		  */
	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	//getch();			/* Wait for user input */
	//char thing = getchar();
	//printw(thing);
	char mesg[] = "Enter: ";
	char str[80];
	int row, col;
	getmaxyx(stdscr, row, col); // get number rows colums
	mvprintw(row/2, (col-strlen(mesg))/2, "%s",mesg);

	getstr(str); // input
	mvprintw(LINES - 2, 0, "You Entered:  %s", str);
	getch();

	move(1,1);

	endwin();			/* End curses mode		  */

	return 0;
}
