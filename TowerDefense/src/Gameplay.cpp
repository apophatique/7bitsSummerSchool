//
// Created by gaziz on 17.09.18.
//

#include "../include/Gameplay.h"
#include "../include/RenderSystem.h"
#include "../include/GetKeyboardPress.h"
#include "../include/FileReadingService.h"
#include "../include/PrototypeFactory.h"
#include "../include/Floor.h"
#include "../include/Road.h"
#include "../include/Wall.h"
#include "../include/IOC.h"

void Gameplay::Start() {
    auto prototypeFactory = std::make_shared<PrototypeFactory>();
    prototypeFactory->put("#", std::make_shared<Wall>(Wall()));
    prototypeFactory->put(".", std::make_shared<Floor>(Floor()));
    prototypeFactory->put(" ", std::make_shared<Road>(Road()));
    IOC::getInstance().put<PrototypeFactory>("PrototypeFactory", prototypeFactory);


    auto renderSystem = std::make_shared<RenderSystem>();
    IOC::getInstance().put<RenderSystem>("RenderSystem", renderSystem);


    FileReadingService FileReadingSerive;
    FileReadingSerive.inputStaticEntities();


    Looping();
}

void Gameplay::Looping() {
    GetKeyboardPress keyboardPress;
    auto renderSystem = IOC::getInstance().get<RenderSystem>("RenderSystem");


    while (true) {

        int get = keyboardPress.getKeyBoardPress();

        renderSystem->evokeOffsetOfStaticEntities(get);

    }
}