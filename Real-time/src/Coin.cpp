//
// Created by gaziz on 17.07.18.
//

#include "../src/Coin.h"
#include <ncurses.h>

char Coin::getCoin() {
    return Coin;
}
void Coin::DrawCoin(int * coordY, int *coordX) {
    mvaddch(*coordY, *coordX, getCoin());
    refresh();
}

void Coin::randomCoins(char **gameMap) {
    int chanceOfCreatingNow = rand_r(&seed) % chance;
    bool chanceFlag = false;
    if (chanceOfCreatingNow >= chanceToBeCreated)
        while (!chanceFlag) {
            int randomCoinsCoordY = rand_r(&seed) % rowsCount;
            int randomCoinsCoordX = rand_r(&seed) % columnsCount;

            if (gameMap[randomCoinsCoordY][randomCoinsCoordX] == '.') {
                gameMap[randomCoinsCoordY][randomCoinsCoordX] = getCoin();
                DrawCoin(&randomCoinsCoordY, &randomCoinsCoordX);
                chanceFlag = true;
            }
        }
}

void Coin::setStartCoins(char **gameMap) {
    int startCoins = 10 + rand_r(&seed) % 10;

    int i = 0;
    while (i != startCoins) {
        int startCoinsCoordY = rand_r(&seed) % rowsCount;
        int startCoinsCoordX = rand_r(&seed) % columnsCount;

        if (gameMap[startCoinsCoordY][startCoinsCoordX] == '.') {
            gameMap[startCoinsCoordY][startCoinsCoordX] = getCoin();
            mvaddch(startCoinsCoordY, startCoinsCoordX, getCoin());
            refresh();
            i++;
        }
    }
}
