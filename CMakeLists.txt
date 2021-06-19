cmake_minimum_required(VERSION 3.19)
project(ex3_Boats_simulation)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex3_Boats_simulation ships_simulation-main/src/Model/Model.cpp ships_simulation-main/src/Model/Model.h)