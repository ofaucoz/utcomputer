cmake_minimum_required(VERSION 2.8)
project(LO21)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# GTK+ / GTKMM
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})
add_definitions(${GTKMM_CFLAGS_OTHER})

# Library
set(LIBRARY_FILES
        lib/exception/invalid_syntax.h
        lib/exception/undefined_atom.h
        lib/exception/invalid_operand.h
        lib/exception/unspported_literal.h
        lib/exception/runtime.h
        lib/math/fraction.h
        lib/math/math.cpp
        lib/math/math.h
        lib/literal/interface.h
        lib/literal/operator.h
        lib/literal/numeric.cpp
        lib/literal/numeric.h
        lib/literal/expression.h
        lib/literal/program.h
        lib/literal/atom.h
        lib/literal/whitespace.h
        lib/literal/parenthesis.h
        lib/literal/comma.h
        lib/literal/stack.h
        lib/literal_definition/interface.h
        lib/literal_definition/atom.h
        lib/literal_definition/whitespace.h
        lib/literal_definition/numeric.cpp
        lib/literal_definition/numeric.h
        lib/literal_definition/operator_numeric.h
        lib/literal_definition/operator_strict_comparison.h
        lib/literal_definition/operator_equal_comparison.h
        lib/literal_definition/expression.h
        lib/literal_definition/program.h
        lib/literal_definition/parenthesis.h
        lib/literal_definition/comma.h
        lib/operator/interface.h
        lib/operator/addition.cpp
        lib/operator/addition.h
        lib/operator/substraction.cpp
        lib/operator/substraction.h
        lib/operator/division.cpp
        lib/operator/division.h
        lib/operator/multiplication.cpp
        lib/operator/multiplication.h
        lib/operator/euclidian_division.cpp
        lib/operator/euclidian_division.h
        lib/operator/modulo.cpp
        lib/operator/modulo.h
        lib/operator/opposite.cpp
        lib/operator/opposite.h
        lib/operator/denominator.cpp
        lib/operator/denominator.h
        lib/operator/numerator.cpp
        lib/operator/numerator.h
        lib/operator/eval.cpp
        lib/operator/eval.h
        lib/operator/stack_clear.cpp
        lib/operator/stack_clear.h
        lib/operator/stack_drop.cpp
        lib/operator/stack_drop.h
        lib/operator/stack_undo.cpp
        lib/operator/stack_undo.h
        lib/operator/stack_redo.cpp
        lib/operator/stack_redo.h
        lib/operator/numeric_complex_build.cpp
        lib/operator/numeric_complex_build.h
        lib/operator/numeric_complex_real.cpp
        lib/operator/numeric_complex_real.h
        lib/operator/numeric_complex_imaginary.cpp
        lib/operator/logic_equals.cpp
        lib/operator/logic_equals.h
        lib/operator/logic_different.cpp
        lib/operator/logic_different.h
        lib/operator/logic_greater.cpp
        lib/operator/logic_greater.h
        lib/operator/logic_greater_equals.cpp
        lib/operator/logic_greater_equals.h
        lib/operator/logic_lesser.cpp
        lib/operator/logic_lesser.h
        lib/operator/logic_lesser_equals.cpp
        lib/operator/logic_lesser_equals.h
        lib/operator/logic_and.cpp
        lib/operator/logic_and.h
        lib/operator/logic_or.cpp
        lib/operator/logic_or.h
        lib/operator/logic_not.cpp
        lib/operator/logic_not.h
        lib/repository/observable.cpp
        lib/repository/observable.h
        lib/repository/map.h
        lib/lexer.cpp
        lib/lexer.h
        lib/resolver.cpp
        lib/resolver.h
        lib/runner.cpp
        lib/runner.h
        lib/utcomputer.h)

set(INTERFACE_FILES
        ui/main.cpp
        ui/main.h
        ui/keyboard_widget.cpp
        ui/keyboard_widget.h
        ui/repository_widget.cpp
        ui/repository_widget.h
        ui/message_tree_view.cpp
        ui/message_tree_view.h
        ui/history_tree_view.cpp
        ui/history_tree_view.h)

configure_file(ui/views/main.glade ui/views/main.glade COPYONLY)
add_executable(LO21 main.cpp ${LIBRARY_FILES} ${INTERFACE_FILES})
target_link_libraries(LO21 pthread ${GTKMM_LIBRARIES} ${GTK3_LIBRARIES})

# Tests
set(TEST_FILES
        lib/tests/math/math.cpp
        lib/tests/literal/all.cpp
        lib/tests/literal/stack.cpp
        lib/tests/literal_definition/atom.cpp
        lib/tests/literal_definition/numeric.cpp
        lib/tests/literal_definition/operator_numeric.cpp
        lib/tests/literal_definition/operator_strict_comparison.cpp
        lib/tests/literal_definition/operator_equal_comparison.cpp
        lib/tests/literal_definition/expression.cpp
        lib/tests/literal_definition/whitespace.cpp
        lib/tests/literal_definition/program.cpp
        lib/tests/literal_definition/parenthesis.cpp
        lib/tests/operator/addition.cpp
        lib/tests/operator/substraction.cpp
        lib/tests/operator/multiplication.cpp
        lib/tests/operator/division.cpp
        lib/tests/operator/euclidian_division.cpp
        lib/tests/operator/modulo.cpp
        lib/tests/operator/opposite.cpp
        lib/tests/operator/numerator.cpp
        lib/tests/operator/denominator.cpp
        lib/tests/operator/eval.cpp
        lib/tests/operator/stack_clear.cpp
        lib/tests/operator/stack_drop.cpp
        lib/tests/operator/numeric_complex_imaginary.cpp
        lib/tests/operator/numeric_complex_build.cpp
        lib/tests/operator/numeric_complex_real.cpp
        lib/tests/operator/logic_equals.cpp
        lib/tests/operator/logic_different.cpp
        lib/tests/operator/logic_greater.cpp
        lib/tests/operator/logic_greater_equals.cpp
        lib/tests/operator/logic_and.cpp
        lib/tests/operator/logic_or.cpp
        lib/tests/operator/logic_not.cpp
        lib/tests/repository/map.cpp
        lib/tests/lexer.cpp
        lib/tests/resolver.cpp
        lib/tests/runner.cpp
        lib/tests/utcomputer.cpp)

add_executable(LO21tests lib/tests/main.cpp ${LIBRARY_FILES} ${TEST_FILES})
target_link_libraries(LO21tests pthread ${GTEST_LIBRARIES})
