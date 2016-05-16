cmake_minimum_required(VERSION 2.8)
project(LO21)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Application
set(SOURCE_FILES
        main.cpp
        lib/utcomputer.cpp
        lib/utcomputer.h
        lib/lexer.cpp
        lib/lexer.h
        lib/resolver.cpp
        lib/resolver.h
        lib/runner.cpp
        lib/runner.h
        lib/exception/invalid_syntax.cpp
        lib/exception/invalid_syntax.h
        lib/literal/interface.cpp
        lib/literal/interface.h
        lib/literal/operator.cpp
        lib/literal/operator.h
        lib/literal/numeric.cpp
        lib/literal/numeric.h
        lib/literal/expression.cpp
        lib/literal/expression.h
        lib/literal/program.cpp
        lib/literal/program.h
        lib/literal/atom.cpp
        lib/literal/atom.h
        lib/literal/whitespace.cpp
        lib/literal/whitespace.h
        lib/repository/interface.cpp
        lib/repository/interface.h
        lib/repository/literals.cpp
        lib/repository/literals.h
        lib/repository/variables.cpp
        lib/repository/variables.h
        lib/repository/programs.cpp
        lib/repository/programs.h
        lib/repository/operators.cpp
        lib/repository/operators.h
        lib/repository/messages.cpp
        lib/repository/messages.h
        lib/literal_definition/interface.cpp
        lib/literal_definition/interface.h
        lib/literal_definition/atom.cpp
        lib/literal_definition/atom.h
        lib/literal_definition/whitespace.cpp
        lib/literal_definition/whitespace.h
        lib/literal_definition/numeric.cpp
        lib/literal_definition/numeric.h
        lib/literal_definition/operator.cpp
        lib/literal_definition/operator.h
        lib/literal_definition/expression.cpp
        lib/literal_definition/expression.h)

add_executable(LO21 ${SOURCE_FILES})

# Tests
set(TEST_FILES
        lib/tests/main.cpp
        lib/tests/literal/all.cpp
        lib/tests/literal_definition/atom.cpp
        lib/tests/literal_definition/numeric.cpp
        lib/tests/literal_definition/operator.cpp
        lib/tests/literal_definition/expression.cpp
        lib/tests/literal_definition/whitespace.cpp
        lib/tests/repository/literals.cpp
        lib/tests/lexer.cpp)

add_executable(LO21tests ${TEST_FILES})
target_link_libraries(LO21tests ${GTEST_LIBRARIES} pthread)