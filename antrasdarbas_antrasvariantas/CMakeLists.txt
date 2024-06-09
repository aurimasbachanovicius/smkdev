cmake_minimum_required(VERSION 3.29)
project(antrasdarbas_antrasvariantas)

set(CMAKE_CXX_STANDARD 20)

add_executable(antrasdarbas_antrasvariantas main.cpp
        studentas.h
        sarasas.h
        studentuGrupesValdymas.h
        failuTvarkytuvas.h
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/studentai.txt ${CMAKE_CURRENT_BINARY_DIR}/studentai.txt COPYONLY)