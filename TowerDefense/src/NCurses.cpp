//
// Created by gaziz on 17.09.18.
//

#include "../include/NCurses.h"
#include <iostream>
void NCurses::Start() {
    initscr();
    clear();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}
void NCurses::End() {
    endwin();
}