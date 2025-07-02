cmake_minimum_required(VERSION 3.29)
project(Events)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Events
    Balrog.h
    BaseFactory.h
    Event.h
    Monster.cpp
    Monster.h
        Balrog.cpp)
