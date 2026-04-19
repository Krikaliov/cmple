# Project configuration

cmake_minimum_required(VERSION 3.15)
project(cmple_testing_maths)

# Compilation configuration

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall")

# Code source without executables (sources with main function)

file(GLOB_RECURSE CORE_SOURCES "src/*.c")

# Building library

add_library(${PROJECT_NAME} STATIC ${CORE_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Test executables

enable_testing()

file(GLOB TEST_SOURCES "tests/*.test.c" "tests/**/*.test.c")
foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(test_${TEST_NAME} ${TEST_SOURCE} ${CORE_SOURCES})
  target_include_directories(test_${TEST_NAME} PRIVATE src/ ../../)
  add_test(NAME ${TEST_NAME} COMMAND test_${TEST_NAME})
endforeach()
