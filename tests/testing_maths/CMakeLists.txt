# Project config

cmake_minimum_required(VERSION 3.15)
project(cmple_testing_maths)

# Build config

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall")

# Code source

file(GLOB_RECURSE CORE_SOURCES "src/*.c")

# Building library

add_library(${PROJECT_NAME} STATIC ${CORE_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Executable tests

file(GLOB TEST_SOURCES "tests/*.test.c" "tests/**/*.test.c")
foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  string(REPLACE ".test" "" TEST_NAME ${TEST_NAME})
  add_executable(test_${TEST_NAME} ${TEST_SOURCE} ${CORE_SOURCES})
  target_include_directories(test_${TEST_NAME} PRIVATE src/ ../../)
  list(APPEND ALL_TEST_TARGETS test_${TEST_NAME})
endforeach()

add_custom_target(run_tests COMMAND ${CMAKE_COMMAND} DEPENDS ${ALL_TEST_TARGETS})

foreach(TEST_TARGET ${ALL_TEST_TARGETS})
  add_custom_command(TARGET run_tests POST_BUILD COMMAND ${TEST_TARGET})
endforeach()
