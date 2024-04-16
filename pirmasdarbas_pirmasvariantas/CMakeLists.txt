cmake_minimum_required(VERSION 3.28)
project(pirmasdarbas_pirmasvariantas)

set(CMAKE_CXX_STANDARD 17)

add_executable(pirmasdarbas_pirmasvariantas main.cpp
        adresuknygute.h
        asmuo.h)


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/adresu_knyga.txt ${CMAKE_CURRENT_BINARY_DIR}/adresu_knyga.txt COPYONLY)