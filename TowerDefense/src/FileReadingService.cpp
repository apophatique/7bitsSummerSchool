//
// Created by gaziz on 15.09.18.
//

#include "../include/FileReadingService.h"
#include "../include/PrototypeFactory.h"
#include <cstdio>
#include <cstdlib>

void FileReadingService::inputStaticEntities() {
    clear();
    std::shared_ptr<int> rowsCount = std::make_shared<int>(0);
    std::shared_ptr<int> columnsCount = std::make_shared<int>(0);
    auto StaticEntitiesVector = std::make_shared<std::vector<std::vector<std::shared_ptr<IStaticEntity>>>>();
    auto renderStaticEntitiesVector = std::make_shared<std::vector<std::vector<std::shared_ptr<IStaticEntity>>>>();
    auto prototypeFactory = IOC::getInstance().get<PrototypeFactory>("PrototypeFactory");
    std::fstream Map("resourses/Map.txt");

    while (Map) {
        std::string buffer {};
        std::getline(Map, buffer);
        std::vector<std::shared_ptr<IStaticEntity>> line;
        for (auto i : buffer) {
            line.push_back(prototypeFactory->get(i));
            if (*rowsCount == 0) {
                (*columnsCount)++;
            }
        }
        if (Map) {
            StaticEntitiesVector->push_back(line);
            (*rowsCount)++;
        }
    }
    std::shared_ptr<int> renderStaticEntitiesSizeX = std::make_shared<int>(50);
    std::shared_ptr<int> renderStaticEntitiesSizeY = std::make_shared<int>(20);
    renderStaticEntitiesVector->assign(static_cast<unsigned long>(*renderStaticEntitiesSizeY), std::vector<std::shared_ptr<IStaticEntity>>(*renderStaticEntitiesSizeX));
    std::shared_ptr<int> renderStaticEntitesMainCoordX = std::make_shared<int>(5);
    std::shared_ptr<int> renderStaticEntitesMainCoordY = std::make_shared<int>(5);

    for (int iRender = 0, iMap = *renderStaticEntitesMainCoordY; iRender < *renderStaticEntitiesSizeY; iRender++, iMap++)
        for (int jRender = 0, jMap = *renderStaticEntitesMainCoordX; jRender < *renderStaticEntitiesSizeX; jRender++, jMap++) {
            renderStaticEntitiesVector->at(static_cast<unsigned long>(iRender)).at(static_cast<unsigned long>(jRender)) =
                    StaticEntitiesVector->at(static_cast<unsigned long>(iMap)).at(static_cast<unsigned long>(jMap));
        }
        

    IOC::getInstance().put<int>("RenderStaticEntitesMainCoordX", renderStaticEntitesMainCoordX);
    IOC::getInstance().put<int>("RenderStaticEntitesMainCoordY", renderStaticEntitesMainCoordY);
    IOC::getInstance().put<int>("RenderStaticEntitiesSizeX", renderStaticEntitiesSizeX);
    IOC::getInstance().put<int>("RenderStaticEntitiesSizeY", renderStaticEntitiesSizeY);
    IOC::getInstance().put<int>("RowsCount", rowsCount);
    IOC::getInstance().put<int>("ColumnsCount", columnsCount);
    IOC::getInstance().put<std::vector<std::vector<std::shared_ptr<IStaticEntity>>>>("StaticEntitiesVector", StaticEntitiesVector);
    IOC::getInstance().put<std::vector<std::vector<std::shared_ptr<IStaticEntity>>>>("RenderStaticEntitiesVector", renderStaticEntitiesVector);
}

