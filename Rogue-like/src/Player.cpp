//
// Created by gaziz on 17.07.18.
//

#include "../src/Player.h"
#include <ncurses.h>
#include <string>
#include <iostream>
#include "../src/Coin.h"
#include "../src/Floor.h"
#include "../src/Map.h"

Map Map;
Floor Floor;
Coin Coin;

char Player::getPlayer() {
    return _Player;
}

void Player::DrawPlayer(int *coordY, int *coordX) {
    mvaddch(*coordY, *coordX, getPlayer());
    refresh();
}

void Player::Move(char **gameMap, int *movesCount, int *thisMapNumber, Leaderboard leaderboard) {
    int pathsCount = 3;
    int coordX = 1, coordY = 1;
    gameMap[coordY][coordX] = _Player;
    DrawPlayer(&coordY, &coordX);
    int timeCoordY = 3;
    int timeCoordX = 20;
    int coordNextY = coordY;
    int coordNextX = coordX;
    int delta = 1;
    while (Moves[*thisMapNumber]) {
        mvprintw(timeCoordY, timeCoordX, "Your moves: %d   "
                                         , Moves[*thisMapNumber]);
        refresh();
        checkDirection();
        coordNextX = coordX + changeDeltaX();
        coordNextY = coordY + changeDeltaY();
        if (gameMap[coordNextY][coordNextX] == Floor.getFloor()) {
            gameMap[coordY][coordX] = Floor.getFloor();
            Floor.drawFloor(&coordY, &coordX);

            coordX+=changeDeltaX();
            coordY+=changeDeltaY();

            gameMap[coordY][coordX] = _Player;
            DrawPlayer(&coordY, &coordX);

            Moves[*thisMapNumber]--;
            *movesCount+=1;
        }

        if (gameMap[coordNextY][coordNextX] == Coin.getCoin()) {
            gameMap[coordY][coordX] = Floor.getFloor();
            Floor.drawFloor(&coordY, &coordX);

            coordX += changeDeltaX();
            coordY += changeDeltaY();

            gameMap[coordY][coordX] = _Player;
            DrawPlayer(&coordY, &coordX);

            Moves[*thisMapNumber]+=Coin.getCoinBonus();
            *movesCount+=1;
        }

        if (gameMap[coordNextY][coordNextX] == '>') {
            *movesCount+=1;
            Moves[*thisMapNumber]--;

            if (*thisMapNumber == pathsCount) {
                *thisMapNumber = 0;
                string path = "resourses/Leaderboard.txt";
                char playerName[20];
                std::cout << "Your name: ";
                std::cin >> playerName;
                leaderboard.update(path, movesCount, playerName);
                leaderboard.showLeaderboard();
                break;
            }

           *thisMapNumber+=1;
           string PathNow = Map.getPaths(thisMapNumber);
            Map.downloadAndDrawMap(&PathNow, movesCount, thisMapNumber, leaderboard);
           break;
        }
    }
}

void Player::setMoves() {
    Moves[0] = 20;
    Moves[1] = 16;
    Moves[2] = 12;
    Moves[3] = 24;
}
int Player::changeDeltaX() {
    if (direction == 'R')
        return 1;

    if (direction == 'L')
        return -1;

    if (direction == 'U')
        return 0;

    if (direction == 'D')
        return 0;
}
int Player::changeDeltaY() {
    if (direction == 'R')
        return 0;

    if (direction == 'L')
        return 0;

    if (direction == 'U')
        return -1;

    if (direction == 'D')
        return 1;
}
void Player::checkDirection() {
    int GetDirection = getch();

    if (GetDirection == KEY_RIGHT)
        direction = 'R';

    if (GetDirection == KEY_LEFT)
        direction = 'L';

    if (GetDirection == KEY_UP)
        direction = 'U';

    if (GetDirection == KEY_DOWN)
        direction = 'D';
}