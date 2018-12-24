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

int Coin::getCoinBonus() {
    int coinBonus = 2;
    return coinBonus;
}