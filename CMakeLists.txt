cmake_minimum_required(VERSION 3.5)
project(LO21)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp literal/interface.cpp literal/interface.h literal/int.cpp literal/int.h literal/rationnal.cpp literal/rationnal.h literal/real.cpp literal/real.h literal/complex.cpp literal/complex.h literal/expression.cpp literal/expression.h literal/program.cpp literal/program.h literal/atom.cpp literal/atom.h)
add_executable(LO21 ${SOURCE_FILES})