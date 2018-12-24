#include <string>
#include <vector>
#include <fstream>

#include "../src/Leaderboard.h"
using namespace std;

void Leaderboard::shorten() {
    size_t arraySize = leaderboardMembers.size();

    for (size_t i = 10; i < arraySize; i++) {
        leaderboardMembers.pop_back();
    }
}

void Leaderboard::writeNewRecordToFile(const std::string &FILE_PATH, int *newScore, char *newNickname) {
    std::ofstream leaderboardFile;
    leaderboardFile.open(FILE_PATH, std::ios_base::app);
    if (!leaderboardFile.is_open()) {
        mvprintw(0, 0, "Error! Cant write to the file");
        getch();
    } else {
        leaderboardFile << '\n' << newNickname << '\n' << *newScore;
        leaderboardFile.close();
    }
}


void Leaderboard::readTableFromFile(const std::string &FILE_PATH) {
    std::ifstream leaderboardFile;
    leaderboardFile.open(FILE_PATH);

    if (!leaderboardFile.is_open()) {
        mvprintw(0, 0, "Error! Can't find the file");
        getch();
    } else {
        leaderboardFile.unsetf(std::ios_base::skipws);
        std::string buffer;
        std::string bufferForNumbers;

        leaderboardFile.get();

        while (!leaderboardFile.eof()) {
            std::getline(leaderboardFile, buffer);

            std::getline(leaderboardFile, bufferForNumbers);

            int64_t numericBuffer;

            numericBuffer = std::stoi(bufferForNumbers);

            LeaderboardMember leaderboardMember {
                    buffer, numericBuffer
            };

            leaderboardMembers.push_back(leaderboardMember);
        }
    }
}

void Leaderboard::sort() {
    for (size_t i = 0; i < leaderboardMembers.size() - 1; i++) {
        for (size_t j = i + 1; j < leaderboardMembers.size(); j++) {
            if (leaderboardMembers[j].score > leaderboardMembers[i].score) {
                LeaderboardMember buffer = leaderboardMembers[i];
                leaderboardMembers[i] = leaderboardMembers[j];
                leaderboardMembers[j] = buffer;
            }
        }
    }
}


void Leaderboard::writeSortedTableToFile(const std::string &FILE_PATH) {
    std::ofstream leaderboardFile;
    leaderboardFile.open(FILE_PATH);

    if (!leaderboardFile.is_open()) {
    } else {
        for (auto &leaderboardMember : leaderboardMembers) {
            leaderboardFile << '\n' << leaderboardMember.nickname
                            << '\n' << leaderboardMember.score;
        }

        leaderboardFile.close();
    }
}

Leaderboard::Leaderboard() : leaderboardMembers {} {}
Leaderboard::~Leaderboard() = default;

void Leaderboard::update(const std::string &FILE_PATH, Time *time) {
        clear();
        int newScore = time->getRecordingTime();
        char *playerName = time->getNameOfRecordTime();
        writeNewRecordToFile(FILE_PATH, &newScore, playerName);
        readTableFromFile(FILE_PATH);
        sort();
        writeSortedTableToFile(FILE_PATH);


    if (static_cast<int>(leaderboardMembers.size()) > leaderboardMaxSize) {
        shorten();
    }
}

void Leaderboard::showLeaderboard() {
    clear();
    mvprintw(textGameOverCoordY, textGameOverCoordX , "Game over ");
    nodelay(stdscr, false);

    mvprintw(texttryAgaonCoordY, texttryAgainCoordX, "Press SPACE to try again ");
    mvprintw(texttryAgaonCoordY + 1, texttryAgainCoordX, "Press TAB to exit the game ");
    mvprintw(textleaderboardCoordY, textleaderboardCoordX, "Leaderboard: ");

    for (int i = 0; i < static_cast<int>(leaderboardMembers.size()); i++) {
        mvprintw(i + textleadersCoordY , textleadersCoordX , "Player %s - %d seconds" ,
                 leaderboardMembers[i].nickname.c_str(), leaderboardMembers[i].score);
        refresh();
    }

    nodelay(stdscr, TRUE);
}

string Leaderboard::getPathForLeaderboard() {
    return PathForLeaderboard;
}