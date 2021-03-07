cmake_minimum_required(VERSION 3.17)
project(chess)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -fopenmp)

include_directories(.)

add_subdirectory(data)
add_subdirectory(game)
add_subdirectory(util)
add_subdirectory(test)

add_executable(chess main.cpp)