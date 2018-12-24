//
// Created by gaziz on 14.08.18.
//

#ifndef GAZIZ_SATTAROV_GAME_TIME_H
#define GAZIZ_SATTAROV_GAME_TIME_H
#include <string>
#include <ncurses.h>
#include <cstdio>
#include <ctime>
#include <random>
#include <chrono>
#include <unistd.h>
#include "../src/Coin.h"

class Time {
 private:
    char *nameOfRecordTime;
    Coin coin;
    int recordingTime = 0;
    int Time = 8;
    unsigned int seed = static_cast <unsigned int>(time(nullptr));
    int bonusForTime = 1 + rand_r(&seed) % 3;
 public:
    ~Time() = default;
    void bonusTime();
    void refreshTime();
    void drawTime();
    void actionsForOneSecond(char **Array);
    int getRecordingTime();
    int *getTime();
    void setNameOfRecordTime(char *_name);
    char* getNameOfRecordTime();
};


#endif  // GAZIZ_SATTAROV_GAME_TIME_H
