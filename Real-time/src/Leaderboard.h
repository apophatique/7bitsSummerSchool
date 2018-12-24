#ifndef GAZIZ_SATTAROV_GAME2_CLASSLEADERBOARD_H
#define GAZIZ_SATTAROV_GAME2_CLASSLEADERBOARD_H

#include <vector>
#include <ncurses.h>
#include <string>
#include "../src/Time.h"


class Leaderboard {
 private:
    int score;

        struct LeaderboardMember {
           std::string nickname;
            int64_t score;
        };

        std::vector<LeaderboardMember> leaderboardMembers;
    int leaderboardMaxSize = 10;

    void shorten();

    void writeNewRecordToFile(const std::string &, int *, char *);

    void readTableFromFile(const std::string &);

    void sort();

    void writeSortedTableToFile(const std::string &);

    std::string PathForLeaderboard = "resourses/Leaderboard.txt";

    int textGameOverCoordY = 3;
    int textGameOverCoordX = 34;
    int texttryAgainCoordX = 50;
    int texttryAgaonCoordY = 20;
    int textleaderboardCoordY = 4;
    int textleaderboardCoordX = 3;
    int textleadersCoordY = 5;
    int textleadersCoordX = 3;

 public:
    Leaderboard();

    ~Leaderboard();

    void update(const std::string &, Time *time);
    void showLeaderboard();
    std::string getPathForLeaderboard();
};

#endif