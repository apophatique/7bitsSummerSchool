//
// Created by gaziz on 18.07.18.
//

#ifndef GAZIZ_SATTAROV_GAME2_CLASSMAP_H
#define GAZIZ_SATTAROV_GAME2_CLASSMAP_H
#include <string>
#include <fstream>
#include <ncurses.h>
#include "../src/Player.h"
#include "../src/Leaderboard.h"

using namespace std;

class Map {
 private:
    string Paths[4] = {"resources/Map1.txt", "resources/Map2.txt",
                       "resources/Map3.txt", "resources/Map4.txt"};
    ifstream Map;
    int rowsCount;
    int columnsCount;
    char **Array;

 public:
    void countRowsAndColumnsInFile(string *, int *, int *);
    void downloadAndDrawMap(string *Path, int *movesCount, int *, Leaderboard leaderboard);
    char getArray(int *, int *);
    void drawMap();
    string getPaths(int *mapNumber);
};



#endif  // GAZIZ_SATTAROV_GAME2_CLASSMAP_H
