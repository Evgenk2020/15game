cmake_minimum_required(VERSION 3.5)

project(fefteen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fefteen main.cpp
    defines.h
    key_detect.h key_detect.cpp
    keys.h keys.cpp
    lib_input.h
    move.h move.cpp
    randomizer.h
    s_input.h s_input.cpp)
