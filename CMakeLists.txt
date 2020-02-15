cmake_minimum_required(VERSION 3.15)
project(learn-cpp-by-making-games-vol1)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_C_COMPILER "/usr/local/bin/gcc-9")
#set(CMAKE_CXX_COMPILER "/usr/local/bin/g++-9")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(learn-cpp-by-making-games-vol1 section14/105UnderstandingBattleship.cpp)
