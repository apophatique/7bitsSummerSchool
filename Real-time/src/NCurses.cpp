//
// Created by gaziz on 16.08.18.
//

#include "../src/NCurses.h"

void NCurses::nCursesStart() {
    initscr();
    raw();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
}
void NCurses::nCursesEnd() {
    endwin();
}