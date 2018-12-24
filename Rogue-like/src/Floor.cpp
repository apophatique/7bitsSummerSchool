//
// Created by gaziz on 24.07.18.
//

#include "../src/Floor.h"
#include <ncurses.h>

char Floor::getFloor() {
    return Floor;
}

void Floor::drawFloor(int *coordY, int *coordX) {
    mvaddch(*coordY, *coordX, getFloor());
    refresh();
}