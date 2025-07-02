cmake_minimum_required(VERSION 3.29)
project(Player)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Player
    Job.cpp
    Job.h
    JobFactory.cpp
    JobFactory.h
    Player.h
    RangedCmbatJob.h
        Archer.h)
