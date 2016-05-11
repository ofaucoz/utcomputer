cmake_minimum_required(VERSION 3.5)
project(LO21)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Application
set(SOURCE_FILES
        main.cpp
        literal/literal_interface.cpp
        literal/literal_interface.h
        literal/int.cpp
        literal/int.h
        literal/rationnal.cpp
        literal/rationnal.h
        literal/real.cpp
        literal/real.h
        literal/complex.cpp
        literal/complex.h
        literal/expression.cpp
        literal/expression.h
        literal/program.cpp
        literal/program.h
        literal/atom.cpp
        literal/atom.h
        repository/repository_interface.cpp
        repository/repository_interface.h
        repository/literals.cpp
        repository/literals.h
        repository/variables.cpp
        repository/variables.h
        repository/programs.cpp
        repository/programs.h
        repository/operators.cpp
        repository/operators.h
        repository/messages.cpp
        repository/messages.h tests/literal/all.cpp)

add_executable(LO21 ${SOURCE_FILES})

# Tests
set(TEST_FILES
        tests/main.cpp
        tests/literal/all.cpp
        tests/repository/literals.cpp
        tests/repository/programs.cpp)

add_executable(LO21tests ${TEST_FILES})
target_link_libraries(LO21tests ${GTEST_LIBRARIES} pthread)