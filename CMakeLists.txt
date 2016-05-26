cmake_minimum_required(VERSION 2.8)
project(LO21)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Application
set(SOURCE_FILES
        lib/debug/tokens_dumper.cpp
        lib/debug/tokens_dumper.h
        lib/exception/invalid_syntax.cpp
        lib/exception/invalid_syntax.h
        lib/exception/undefined_atom.cpp
        lib/exception/undefined_atom.h
        lib/exception/invalid_operand.cpp
        lib/exception/invalid_operand.h
        lib/exception/unspported_literal.cpp
        lib/exception/unspported_literal.h
        lib/math/fraction.cpp
        lib/math/fraction.h
        lib/math/math.cpp
        lib/math/math.h
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
        lib/literal_definition/expression.h
        lib/literal_definition/program.cpp
        lib/literal_definition/program.h
        lib/operator/interface.cpp
        lib/operator/interface.h
        lib/operator/plus.cpp
        lib/operator/plus.h
        lib/repository/observable.cpp
        lib/repository/observable.h
        lib/repository/map.cpp
        lib/repository/map.h
        lib/repository/stack.cpp
        lib/repository/stack.h
        lib/lexer.cpp
        lib/lexer.h
        lib/resolver.cpp
        lib/resolver.h
        lib/runner.cpp
        lib/runner.h
        lib/utcomputer.cpp
        lib/utcomputer.h)

add_executable(LO21 main.cpp ${SOURCE_FILES})

# Tests
set(TEST_FILES
        lib/tests/math/math.cpp
        lib/tests/literal/all.cpp
        lib/tests/literal_definition/atom.cpp
        lib/tests/literal_definition/numeric.cpp
        lib/tests/literal_definition/operator.cpp
        lib/tests/literal_definition/expression.cpp
        lib/tests/literal_definition/whitespace.cpp
        lib/tests/operator/plus.cpp
        lib/tests/repository/map.cpp
        lib/tests/repository/stack.cpp
        lib/tests/lexer.cpp
        lib/tests/resolver.cpp
        lib/tests/runner.cpp)

add_executable(LO21tests lib/tests/main.cpp ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(LO21tests ${GTEST_LIBRARIES} pthread)
