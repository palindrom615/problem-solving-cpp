project(problem_solving_cpp CXX)

cmake_minimum_required(VERSION 3.17)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "Vcpkg toolchain file")
include(${CMAKE_TOOLCHAIN_FILE})

set(EXECUTABLE_OUTPUT_PATH "build")
set(LIBRARY_OUTPUT_PATH "build")
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB_RECURSE SOURCES solutions/*.cpp)
foreach (SRC ${SOURCES})
    get_filename_component(BIN ${SRC} NAME_WE)
    add_executable(${BIN} ${SRC})

    string(REPLACE ".cpp" ".in" TEST_INPUT ${SRC})
    string(REPLACE ".cpp" ".out" TEST_OUTPUT ${SRC})
    if (EXISTS ${TEST_INPUT})
        add_library(${BIN}_lib OBJECT ${SRC})
        target_compile_definitions(${BIN}_lib PRIVATE main=executable_main)
        add_executable(${BIN}_test $<TARGET_OBJECTS:${BIN}_lib> test/test.cpp)
        target_compile_definitions(${BIN}_test PUBLIC TEST TEST_INPUT="${TEST_INPUT}" TEST_OUTPUT="${TEST_OUTPUT}")

        find_path(BOOST_ALGORITHM_INCLUDE_DIRS "boost/algorithm/algorithm.hpp")
        target_include_directories(${BIN}_test PRIVATE ${BOOST_ALGORITHM_INCLUDE_DIRS})
    endif ()
endforeach ()
