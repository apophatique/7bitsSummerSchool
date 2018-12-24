//
// Created by gaziz on 17.07.18.
//

#ifndef GAZIZ_SATTAROV_GAME_CLASSCOINS_H
#define GAZIZ_SATTAROV_GAME_CLASSCOINS_H


class Coin {
 private:
    char Coin  = '$';
    int coinBonus;
 public:
    char getCoin();
    void DrawCoin(int *, int *);
    int getCoinBonus();
};



#endif  // GAZIZ_SATTAROV_GAME_CLASSCOINS_H
