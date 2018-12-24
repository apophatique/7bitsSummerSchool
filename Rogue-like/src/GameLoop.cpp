//
// Created by gaziz on 14.08.18.
//

#include "../src/GameLoop.h"
#include <string>
void GameLoop::startGame() {
    Map Map;
    Leaderboard leaderboard;
    bool gameFlag = true;
    int keyboardSpaceNumber = 32;
    int keyboardTabNumber = 9;
    int playChoose = 0;

    while (gameFlag) {
        int movesCount = 0;
        int PathCount = 0;
        int thisMapNumber = 0;
        string Path = Map.getPaths(&PathCount);
        Map.downloadAndDrawMap(&Path, &movesCount, &thisMapNumber, leaderboard);

        while (playChoose !=keyboardSpaceNumber  || playChoose != keyboardTabNumber) {
            playChoose = getch();
            if (playChoose == keyboardSpaceNumber)
                break;
            if (playChoose == keyboardTabNumber)
            { gameFlag = false;
                break;
            }
        }
    }
}