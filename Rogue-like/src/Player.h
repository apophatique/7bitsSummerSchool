//
// Created by gaziz on 17.07.18.
//

#ifndef GAZIZ_SATTAROV_GAME_PLAYERCLASS_H
#define GAZIZ_SATTAROV_GAME_PLAYERCLASS_H
#include <ncurses.h>
#include "../src/Coin.h"
#include "../src/Floor.h"
#include "../src/Leaderboard.h"


class Player {
 private:
        char _Player = '@';
        int Moves[4] = {20, 16, 12, 24};
        char direction{};
 public:
    void setMoves();
    char getPlayer();
    void DrawPlayer(int *, int *);
    void Move(char **gameMap, int *movesCount, int *, Leaderboard leaderboard);
    void checkDirection();
    int changeDeltaX();
    int changeDeltaY();
};


#endif  // GAZIZ_SATTAROV_GAME_PLAYERCLASS_H
