cmake_minimum_required(VERSION 3.5)
project(LO21)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(LO21 ${SOURCE_FILES})