//
// Created by gaziz on 14.08.18.
//

#ifndef GAZIZ_SATTAROV_GAME_GAMELOOP_H
#define GAZIZ_SATTAROV_GAME_GAMELOOP_H
#include "../src/Map.h"
#include "../src/Player.h"
#include "../src/Leaderboard.h"
#include "../src/Time.h"
#include "../src/NCurses.h"

class GameLoop {
 public:
void startGame();
void gameLooping(Time *time, char **Array);
};


#endif  // GAZIZ_SATTAROV_GAME_GAMELOOP_H
