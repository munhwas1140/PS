#include <iostream>
#include <string>
#include <clocale>
#include <curses.h>

using namespace std;
int main(void) {
	string unicode[100] = {"\u25A1", "\u25A0"}; // □, ■

	setlocale(LC_ALL, "");

	initscr();

	start_color();

	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLUE);

	bkgd(COLOR_PAIR(1));

	attron(COLOR_PAIR(1));
	mvprintw(3, 4, "\u25A1 \u25A0");
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(2));
	border('*', '*', '*', '*', '*', '*', '*', '*');
	attroff(COLOR_PAIR(2));

	refresh();
	getch();
	endwin();

	return 0;
}