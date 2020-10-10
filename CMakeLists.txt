cmake_minimum_required(VERSION 3.15)

# set the project name and version learn-cpp-by-making-games-vol1
project(SpaceInvaders VERSION 0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_DEBUG_POSTFIX _debug)

add_library(space_invaders_compiler_flags INTERFACE)
target_compile_definitions(space_invaders_compiler_flags INTERFACE cxx_std_17)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(space_invaders_compiler_flags INTERFACE
        "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
        "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
        )

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(SpaceInvaders section18/CursesUtils.h section18/CursesUtils.cpp section18/TextInvaders.cpp section18/TextInvaders.h)
set_target_properties(SpaceInvaders PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

target_link_libraries(SpaceInvaders PUBLIC ${CURSES_LIBRARIES})
