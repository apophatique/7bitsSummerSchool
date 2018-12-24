//
// Created by gaziz on 18.07.18.
//

#ifndef GAZIZ_SATTAROV_GAME_WALLCLASS_H
#define GAZIZ_SATTAROV_GAME_WALLCLASS_H


class Floor {
 private:
    char floor = '.';
 public:
    char getFloor();
    void drawFloor(int *coordY, int *coordX);
};


#endif  // GAZIZ_SATTAROV_GAME_WALLCLASS_H
