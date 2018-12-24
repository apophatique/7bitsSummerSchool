//
// Created by gaziz on 17.09.18.
//


#include "../include/RenderSystem.h"
#include <functional>

void RenderSystem::showRenderStaticEntities() {

    auto renderStaticEntitiesSizeX = IOC::getInstance().get<int>("RenderStaticEntitiesSizeX");
    auto renderStaticEntitiesSizeY = IOC::getInstance().get<int>("RenderStaticEntitiesSizeY");
    auto StaticEntitiesVector = IOC::getInstance().get<std::vector<std::vector<std::shared_ptr<IStaticEntity>>>>("RenderStaticEntitiesVector");

    for (int i = 0; i < *renderStaticEntitiesSizeY; i++) {
        for (int j = 0; j < *renderStaticEntitiesSizeX; j++) {
          mvaddch(gameMapRenderCoordY + i, gameMapRenderCoordX + j, StaticEntitiesVector->at(i).at(j)->getEntityModel());
        }
    }

    refresh();
}

void RenderSystem::refreshRenderStaticEntites() {
    auto renderStaticEntitesMainCoordY = IOC::getInstance().get<int>("RenderStaticEntitesMainCoordY");
    auto renderStaticEntitesMainCoordX = IOC::getInstance().get<int>("RenderStaticEntitesMainCoordX");

    auto renderStaticEntitiesSizeX = IOC::getInstance().get<int>("RenderStaticEntitiesSizeX");
    auto renderStaticEntitiesSizeY = IOC::getInstance().get<int>("RenderStaticEntitiesSizeY");

    auto StaticEntitiesVector = IOC::getInstance().get<std::vector<std::vector<std::shared_ptr<IStaticEntity>>>>("StaticEntitiesVector");
    auto renderStaticEntitiesVector = IOC::getInstance().get<std::vector<std::vector<std::shared_ptr<IStaticEntity>>>>
            ("RenderStaticEntitiesVector");

    for (int iRender = 0, iMap = *renderStaticEntitesMainCoordY; iRender < *renderStaticEntitiesSizeY; iRender++, iMap++)
        for (int jRender = 0, jMap = *renderStaticEntitesMainCoordX; jRender < *renderStaticEntitiesSizeX; jRender++, jMap++) {
           renderStaticEntitiesVector->at(iRender).at(jRender) =
                    StaticEntitiesVector->at(iMap).at(jMap);
        }

    showRenderStaticEntities();
}
typedef void (RenderSystem::*FunctionPointer)();

void RenderSystem::evokeOffsetOfStaticEntities(int keyboardPressValue) {

    std::map<std::string, FunctionPointer> RenderFunctionMap;

    RenderFunctionMap["Right"] = &RenderSystem::offsetRightStaticEntities;
    RenderFunctionMap["Left"] = &RenderSystem::offsetLeftStaticEntities;
    RenderFunctionMap["Up"] = &RenderSystem::offsetUpStaticEntities;
    RenderFunctionMap["Down"] = &RenderSystem::offsetDownStaticEntities;

    if (keyboardPressValue == KEY_RIGHT)
        id = "Right";
    if (keyboardPressValue == KEY_LEFT)
        id = "Left";
    if (keyboardPressValue == KEY_UP)
        id = "Up";
    if (keyboardPressValue == KEY_DOWN)
        id = "Down";
    
    std::invoke(RenderFunctionMap.at(id), this);
    refreshRenderStaticEntites();
}

void RenderSystem::offsetRightStaticEntities() {
    auto renderStaticEntitesMainCoordX = IOC::getInstance().get<int>("RenderStaticEntitesMainCoordX");
    (*renderStaticEntitesMainCoordX)++;
}

void RenderSystem::offsetLeftStaticEntities() {
    auto renderStaticEntitesMainCoordX = IOC::getInstance().get<int>("RenderStaticEntitesMainCoordX");
    (*renderStaticEntitesMainCoordX)--;
}

void RenderSystem::offsetUpStaticEntities() {
    auto renderStaticEntitesMainCoordY = IOC::getInstance().get<int>("RenderStaticEntitesMainCoordY");
    (*renderStaticEntitesMainCoordY)--;
}

void RenderSystem::offsetDownStaticEntities() {
    auto renderStaticEntitesMainCoordY = IOC::getInstance().get<int>("RenderStaticEntitesMainCoordY");
    (*renderStaticEntitesMainCoordY)++;
}