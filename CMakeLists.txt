cmake_minimum_required(VERSION 3.16)
project(AdamOptmizer)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(AdamOptmizer
        AdamOptimizer.cpp
        AdamOptimizer.hpp
        main.cpp)
