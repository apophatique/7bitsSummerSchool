//
// Created by gaziz on 17.09.18.
//

#ifndef FIRSTTRY_RENDERSYSTEM_H
#define FIRSTTRY_RENDERSYSTEM_H
#include "../include/IOC.h"
#include "../include/IStaticEntity.h"
#include <ncurses.h>
#include <vector>
#include <map>


class RenderSystem {
private:
    int gameMapRenderCoordX = 6;
    int gameMapRenderCoordY = 4;

public:
    void showRenderStaticEntities();
    void evokeOffsetOfStaticEntities(int keyboardPressValue);
    void refreshRenderStaticEntites();
    void offsetRightStaticEntities();
    void offsetLeftStaticEntities();
    void offsetUpStaticEntities();
    void offsetDownStaticEntities();
    std::string id{};
};


#endif //FIRSTTRY_RENDERSYSTEM_H
