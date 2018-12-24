//
// Created by gaziz on 18.07.18.
//

#include "../src/Map.h"
#include <fstream>
#include <ncurses.h>
#include <string>
#include "../src/Player.h"
Player player;

void Map::drawMap() {
    for (int i =0; i < rowsCount; i++)
        for (int j = 0; j < columnsCount; j++)
            mvaddch(i, j, Array[i][j]);

    refresh();
}
void Map::downloadAndDrawMap(string *Path, int *movesCount,
                             int *thisMapNumber, Leaderboard leaderboard) {
    player.setMoves();
    clear();
    countRowsAndColumnsInFile(Path, &rowsCount, &columnsCount);

    Array = new char *[rowsCount];
    for (int i = 0; i < rowsCount; i++)
        Array[i] = new char[columnsCount];

    Map.open(*Path);
    Map.unsetf(std::ios_base::skipws);

    for (int i = 0; i < rowsCount; i++)
        for (int j = 0; j < columnsCount; j++) {
            Map >> Array[i][j];
            if (Array[i][j] == ' ' || Array[i][j] == '\n')
                Map >> Array[i][j];
        }

    Map.close();
    clear();
    drawMap();
    player.Move(Array, movesCount, thisMapNumber, leaderboard);
}

void Map::countRowsAndColumnsInFile(string *Path, int *rowsCount, int *columnsCount) {
    Map.open(*Path);
    Map.unsetf(std::ios_base::skipws);
    int rowsCounter = 0;
    int columnsCounter = 0;
    bool isFirstLine = true;
    if (!Map.is_open()) {
        int textCoordY = 1;
        int textCoordX = 1;
        mvprintw(textCoordY, textCoordX, "Can not open .txt files");
        getch();
    } else {
        while (Map) {
            char buffer;
            Map >> buffer;
            if (buffer == '\n') {
                if (isFirstLine) {
                    *columnsCount = columnsCounter;
                    isFirstLine = false;
                }
                rowsCounter++;
            } else {
                if (isFirstLine) {
                    columnsCounter++;
                }
            }
        }
        rowsCounter++;
        *rowsCount = rowsCounter;
    }
    Map.close();
}

string Map::getPaths(int *mapNumber) {
    if (*mapNumber == 0)
        return "resourses/Map1.txt";

    if (*mapNumber == 1)
        return "resourses/Map2.txt";

    if (*mapNumber == 2)
        return "resourses/Map3.txt";

    if (*mapNumber == 3)
        return "resourses/Map4.txt";
}

char Map::getArray(int *rowsCount, int *columnsCount) {
    return Array[*rowsCount][*columnsCount];
}