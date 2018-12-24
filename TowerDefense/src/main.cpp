
#include "../include/NCurses.h"
#include "../include/Gameplay.h"

int main() {

    NCurses nCurses;
    nCurses.Start();


    auto gameLooping = std::make_shared<Gameplay>();
    gameLooping->Start();

    nCurses.End();

    return 0;
}
