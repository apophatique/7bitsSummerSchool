cmake_minimum_required(VERSION 3.10)

project(gaziz_sattarov_game LANGUAGES CXX) # имя проекта и язык используемый в проекте (c++)

set(CMAKE_CXX_STANDARD 17) # стандарт с++ 2017
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wno-unused-parameter -Wno-undefined-var-template -fPIC -march=native")

set(CMAKE_CXX_FLAGS_RELEASE "-O3") # включаем оптимизаци компилятора

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")  # добавляем дебажные символы в бинарный файл для дебага

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake") # добавляем дополнительные модули CMake

# Подключаем библиотеку ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
SET(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src)
SET(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES_DIR}/main.cpp src/Player.cpp src/Player.h src/Coin.cpp src/Coin.h src/Floor.cpp src/Floor.h src/Map.cpp src/Map.h src/GameLoop.cpp src/GameLoop.h src/Time.cpp src/Time.h src/Leaderboard.h src/Leaderboard.cpp src/NCurses.cpp src/NCurses.h)



# линкуем библиотеки к проекту

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARY})

include(CppLint)
ADD_STYLE_CHECK_TARGET(lint ${PROJECT_HEADERS_DIR} ${PROJECT_SOURCES_DIR})
