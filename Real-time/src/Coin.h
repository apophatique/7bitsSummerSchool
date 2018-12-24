//
// Created by gaziz on 17.07.18.
//

#ifndef GAZIZ_SATTAROV_GAME_CLASSCOINS_H
#define GAZIZ_SATTAROV_GAME_CLASSCOINS_H
#include <random>


class Coin {
 private:
    int rowsCount = 25;
    int columnsCount = 56;
    unsigned int seed = static_cast <unsigned int>(time(nullptr));
    const int chance = 30;
    int chanceToBeCreated = 16;
    char Coin  = '$';
 public:
    char getCoin();
    void DrawCoin(int *, int *);
    void randomCoins(char **Array);
    void setStartCoins(char **Array);
};


#endif  // GAZIZ_SATTAROV_GAME_CLASSCOINS_H
