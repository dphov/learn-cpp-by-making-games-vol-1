cmake_minimum_required(VERSION 3.15)
project(learn-cpp-by-making-games-vol1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(learn-cpp-by-making-games-vol1 section18/CursesUtils.h section18/CursesUtils.cpp section18/TextInvaders.cpp section18/TextInvaders.h)
target_link_libraries(learn-cpp-by-making-games-vol1 ${CURSES_LIBRARIES})