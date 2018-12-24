//
// Created by gaziz on 14.08.18.
//

#include "../src/Time.h"

void Time::bonusTime() {
    Time += bonusForTime;
    drawTime();
}

void Time::refreshTime() {
    Time--;
    drawTime();
}

void Time::drawTime() {
    int YourTimeCoordY = 10;
    int YourTimeCoordX = 60;
    mvprintw(YourTimeCoordY, YourTimeCoordX, "Your time: %i ", Time);
    refresh();
}

int *Time::getTime() {
    return &Time;
}

void Time::actionsForOneSecond(char **Array) {
    coin.randomCoins(Array);
    recordingTime+=1;
    refreshTime();
}
int Time::getRecordingTime() {
    return recordingTime;
}

void Time::setNameOfRecordTime(char *_name) {
    nameOfRecordTime = _name;
}

char* Time::getNameOfRecordTime() {
    return nameOfRecordTime;
}
