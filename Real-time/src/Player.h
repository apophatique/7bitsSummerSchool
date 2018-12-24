//
// Created by gaziz on 17.07.18.
//

#ifndef GAZIZ_SATTAROV_GAME_PLAYERCLASS_H
#define GAZIZ_SATTAROV_GAME_PLAYERCLASS_H
#include <ncurses.h>
#include "../src/Coin.h"
#include "../src/Floor.h"
#include "../src/Time.h"
#include <random>


class Player {
 private:
    Coin coin;
    Floor floor;
    int rowsCount = 25;
    int columnsCount = 56;
    int startCoordX = 0;
    int startCoordY = 0;
    char playerSign = '@';
    unsigned int seed = static_cast <unsigned int>(time(nullptr));
 public:
    void checkForMoving(char **Array, Time *time, char direction, int *coordX, int *coordY);
    char getPlayer();
    void Move(char **Array, int *, int *, int *, int *, Time *time);
    void DrawPlayer(int *, int *);
    void creatingPlayer(char **Array);
    int getStartCoordX();
    int getStartCoordY();
};


#endif  // GAZIZ_SATTAROV_GAME_PLAYERCLASS_H
