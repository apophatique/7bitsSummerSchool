//
// Created by gaziz on 14.08.18.
//

#include <cstddef>
#include "../src/Map.h"
#include <ncurses.h>
#include "../src/Coin.h"
Coin coin;

void Map::drawMap() {
    for (int i = 0; i < rowsCount; i++)
        for (int j = 0; j < columnsCount; j++)
            mvaddch(i, j, Array[i][j]);
    refresh();
}

void Map::creatingMap() {
    Array = new char *[rowsCount];
    for (int i = 0; i < rowsCount; i++) {
        Array[i] = new char[columnsCount];
    }
    Map.open("src/Map.txt");

    int i = 0;
    int j = 0;
    char thisChar{};

    while (i != 25) {
        if (j < 56) {
            Map >> thisChar;
            Array[i][j] = thisChar;
            j++;

        } else {
            i++;
            j = 0;
        }
    }
    drawMap();
    coin.setStartCoins(Array);
}

char **Map::getArray() {
    return Array;
}