//
// Created by gaziz on 14.08.18.
//

#ifndef GAZIZ_SATTAROV_GAME_MAP_H
#define GAZIZ_SATTAROV_GAME_MAP_H
#include <fstream>
#include <ncurses.h>
#include <string>
#include "../src/Coin.h"

class Map {
 private:
    char **Array;
    const int rowsCount = 25;
    const int columnsCount = 56;
    std::ifstream Map;
 public:
    ~Map() {
        for (int i = 0; i < rowsCount; i++) {
            delete [] Array[i];
        }

        delete [] Array;
    }
    void creatingMap();
    void drawMap();
    char **getArray();
};


#endif  // GAZIZ_SATTAROV_GAME_MAP_H
