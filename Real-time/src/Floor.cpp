//
// Created by gaziz on 18.07.18.
//

#include "../src/Floor.h"
#include <ncurses.h>
#include "../src/Coin.h"

char Floor::getFloor() {
    return floor;
}

void Floor::drawFloor(int *coordY, int *coordX) {
    mvaddch(*coordY, *coordX, getFloor());
    refresh();
}