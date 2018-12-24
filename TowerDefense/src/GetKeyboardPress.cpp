//
// Created by gaziz on 24.09.18.
//

#include <ncurses.h>
#include "../include/GetKeyboardPress.h"

int GetKeyboardPress::getKeyBoardPress() {
    keyboardPress = getch();

    return keyboardPress;
}