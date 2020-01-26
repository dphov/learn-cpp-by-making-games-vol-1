cmake_minimum_required(VERSION 3.15)
project(tic-tac-toe)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_COMPILER "/usr/local/bin/gcc-9")
set(CMAKE_CXX_COMPILER "/usr/local/bin/g++-9")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(tic-tac-toe
        Utils.h
        Utils.cpp
        main.cpp)