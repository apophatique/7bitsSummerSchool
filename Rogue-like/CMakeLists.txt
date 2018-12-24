cmake_minimum_required(VERSION 3.10)
project(gaziz_sattarov_game2)


set(CMAKE_CXX_STANDARD 14) # стандарт с++ 2017
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wswitch-default -Wfloat-equal -Wno-unused-parameter -fPIC -march=native")
set(CMAKE_CXX_FLAGS_RELEASE "-O3") # включаем оптимизаци компилятора

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")  # добавляем дебажные символы в бинарный файл для дебага

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake") # добавляем дополнительные модули CMake

# Подключаем библиотеку ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

SET(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src)
SET(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)

FILE(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
FILE(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} src/Leaderboard.cpp src/Leaderboard.h src/GameLoop.cpp src/GameLoop.h)

# линкуем библиотеки к проекту
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARY})

include(CppLint)
ADD_STYLE_CHECK_TARGET(lint ${PROJECT_HEADERS_DIR} ${PROJECT_SOURCES_DIR})



