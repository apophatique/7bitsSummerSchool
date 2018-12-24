//
// Created by gaziz on 14.08.18.
//
#include <string>
#include <iostream>
#include "../src/GameLoop.h"
using namespace std;


void GameLoop::startGame()  {
    Leaderboard leaders;
    NCurses nCurses;
    nCurses.nCursesStart();

    bool gameFlag = true;
    std::string pathForLeaderboard = leaders.getPathForLeaderboard();

    while (gameFlag) {
        Map map {};
        Time time {};
        nodelay(stdscr, FALSE);
        char playerName[20];
        std::cout << "Your name: ";
        std::cin >> playerName;
        time.setNameOfRecordTime(playerName);
        nodelay(stdscr, TRUE);
        int playerChoose = 0;
        map.creatingMap();
        char **Array = map.getArray();

        gameLooping(&time, Array);

        leaders.update(pathForLeaderboard, &time);
        leaders.showLeaderboard();

        int keyboardSpaceNumber = 32;
        int keyboardTabNumber = 9;
        while (playerChoose != keyboardSpaceNumber || playerChoose != keyboardTabNumber) {
            playerChoose = getch();
            if (playerChoose == keyboardSpaceNumber) {
                clear();
                break;
            }
            if (playerChoose == keyboardTabNumber)
            { gameFlag = false;
                break;
            }
        }
    }
    nCurses.nCursesEnd();
}

void GameLoop::gameLooping(Time *time, char **Array) {
    Player player;
    player.creatingPlayer(Array);
    time->drawTime();
    int *Time = time->getTime();
    int coordX = player.getStartCoordX();
    int coordY = player.getStartCoordY();
    char direction = 'R';
    using tickDuration = std::chrono::duration<int64_t, std::ratio<1, 30>>;
    auto startTimePointForGamelooping = std::chrono::high_resolution_clock::now();
    auto startTimePointForCountingSeconds = std::chrono::high_resolution_clock::now();

    while (*Time) {
        auto endTimePointForGamelooping = std::chrono::high_resolution_clock::now();
        auto endTimePointForCountingSeconds = std::chrono::high_resolution_clock::now();
        auto differenceBetweenTimePointsForGamelooping =
                std::chrono::duration_cast<tickDuration>(endTimePointForGamelooping - startTimePointForGamelooping);

        if (differenceBetweenTimePointsForGamelooping.count() == 1) {
            player.checkForMoving(Array, time, direction, &coordX, &coordY);
            startTimePointForGamelooping = std::chrono::high_resolution_clock::now();
        }

        auto differenceBetweenTimePointsForCountingSeconds =
                std::chrono::duration_cast<std::chrono::seconds>
                        (endTimePointForCountingSeconds - startTimePointForCountingSeconds);

        if (differenceBetweenTimePointsForCountingSeconds.count() == 1) {
            time->actionsForOneSecond(Array);
            startTimePointForCountingSeconds = std::chrono::high_resolution_clock::now();
        }

        int GetDirection = getch();

        if (GetDirection == KEY_RIGHT)
            direction = 'R';
        if (GetDirection == KEY_LEFT)
            direction = 'L';
        if (GetDirection == KEY_UP)
            direction ='U';
        if (GetDirection == KEY_DOWN)
            direction = 'D';
    }
    clear();
}