# Project config

cmake_minimum_required(VERSION 3.15)
project(cmple_testing_strings)

# Build config

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall")

# Code source

file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# Building library

add_library(${PROJECT_NAME} STATIC ${CORE_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC src)

# Executable tests

enable_testing()
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.test.c")
foreach(TEST_SRC ${TEST_SOURCES})
    get_filename_component(FILE_NAME ${TEST_SRC} NAME)
    
    string(REGEX REPLACE "\\.test\\.c$" "" TEST_NAME ${FILE_NAME})
    set(TARGET_NAME "test_${TEST_NAME}")

    add_executable(${TARGET_NAME} ${TEST_SRC})

    target_link_libraries(${TARGET_NAME} PRIVATE ${PROJECT_NAME})
    target_include_directories(${TARGET_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/tests")
    target_include_directories(${TARGET_NAME} PRIVATE "../../")
    add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
endforeach()
