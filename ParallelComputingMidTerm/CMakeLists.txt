cmake_minimum_required(VERSION 3.12)
project(ParallelComputingMidTerm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fopenmp")

add_executable(ParallelComputingMidTerm main.cpp Serial.cpp Serial.h Result.cpp Result.h ParallelOpenMP.cpp ParallelOpenMP.h)