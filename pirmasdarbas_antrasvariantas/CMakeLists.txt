cmake_minimum_required(VERSION 3.28)
project(pirmasdarbas)

set(CMAKE_CXX_STANDARD 17)

add_executable(pirmasdarbas main.cpp
        sportsman.cpp
        sportsman.h
        team.cpp
        team.h
        teamFileLoader.cpp
        teamFileLoader.h
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dream_team.txt ${CMAKE_CURRENT_BINARY_DIR}/dream_team.txt COPYONLY)