cmake_minimum_required(VERSION 3.19)
project(ex3_Boats_simulation)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex3_Boats_simulation main.cpp Boat.h patrolBoat.cpp patrolBoat.h cruiserBoat.cpp cruiserBoat.h freighterBoat.cpp freighterBoat.h gameObj.h)