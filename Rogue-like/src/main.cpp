
#include <ncurses.h>
#include <curses.h>
#include "../src/GameLoop.h"

int main() {
    GameLoop gameLoop;
    initscr();
    raw();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);


    gameLoop.startGame();
    endwin();
    return 0;
}
