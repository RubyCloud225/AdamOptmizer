cmake_minimum_required(VERSION 4.3)
project(AdamOptmizer)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(AdamOptmizer
        AdamOptimizer.cpp
        AdamOptimizer.hpp
        main.cpp)
