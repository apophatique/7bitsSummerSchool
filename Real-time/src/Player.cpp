//
// Created by gaziz on 17.07.18.
//

#include "../src/Player.h"
#include <ncurses.h>
#include "../src/Coin.h"
#include "../src/Floor.h"


char Player::getPlayer() {
    return playerSign;
}

void Player::DrawPlayer(int *coordY, int *coordX) {
    mvaddch(*coordY, *coordX, getPlayer());
    refresh();
}


void Player::creatingPlayer(char **gameMap) {
    while (true) {
        startCoordY = rand_r(&seed) % rowsCount;
        startCoordX = rand_r(&seed) % columnsCount;

        if (gameMap[startCoordY][startCoordX] == '.') {
            gameMap[startCoordY][startCoordX] = getPlayer();
            mvaddch(startCoordY, startCoordX, gameMap[startCoordY][startCoordX]);
            refresh();
            break;
        } else {
            continue;
        }
    }
}

void Player::checkForMoving(char **Array, Time *time, char direction, int *coordX, int *coordY) {
    if (direction == 'R') {
        int deltaX = 1;
        int deltaY = 0;
        Move(Array, coordX, coordY, &deltaX, &deltaY, time);
    }

    if (direction == 'L') {
        int deltaX = -1;
        int deltaY = 0;
        Move(Array, coordX, coordY, &deltaX, &deltaY, time);
    }

    if (direction == 'U') {
        int deltaX = 0;
        int deltaY = -1;
        Move(Array, coordX, coordY, &deltaX, &deltaY, time);
    }

    if (direction == 'D') {
        int deltaX = 0;
        int deltaY = 1;
        Move(Array, coordX, coordY, &deltaX, &deltaY, time);
    }
}


void Player::Move(char **Array, int *coordX, int *coordY,
                  int *deltaX, int *deltaY, Time *time) {
    int coordNextX = (*coordX)+(*deltaX);
    int coordNextY = (*coordY)+(*deltaY);

    if (Array[coordNextY][coordNextX] == floor.getFloor()) {
        Array[*coordY][*coordX] = floor.getFloor();

        floor.drawFloor(coordY, coordX);
        *coordX+=*deltaX;
        *coordY+=*deltaY;
        DrawPlayer(coordY, coordX);
    } else {
        if (Array[coordNextY][coordNextX] == coin.getCoin()) {
            Array[*coordY][*coordX] = floor.getFloor();

            floor.drawFloor(coordY, coordX);

            *coordX += *deltaX;
            *coordY += *deltaY;

            Array[*coordY][*coordX] = getPlayer();
            DrawPlayer(coordY, coordX);

            time->bonusTime();
        }
    }
}

int Player::getStartCoordX() {
    return startCoordX;
}
int Player::getStartCoordY() {
    return startCoordY;
}
