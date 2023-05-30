cmake_minimum_required(VERSION 3.2)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
#SET(CMAKE_BUILD_TYPE Debug)

SET(CMAKE_BUILD_RPATH app)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_BUILD_RPATH}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BUILD_RPATH}/bin)

project(fefteen LANGUAGES CXX)

add_executable(fefteen main.cpp
    defines.h
    key_detect.h key_detect.cpp
    keys.h keys.cpp
    lib_input.h
    move.h move.cpp
    randomizer.h
    s_input.h s_input.cpp)
