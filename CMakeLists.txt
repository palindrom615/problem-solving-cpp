cmake_minimum_required(VERSION 3.17)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "Vcpkg toolchain file")
set(CMAKE_INSTALL_PREFIX, "dist")

project(problem_solving_cpp)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES solutions/*.cpp)
file(GLOB UTILS utils/*.cpp)

foreach (SRC ${SOURCES})
    get_filename_component(BIN ${SRC} NAME_WE)
    add_executable(${BIN} ${SRC})

    add_executable(${BIN}_test test/test.cpp ${SRC})
    string(REPLACE ".cpp" ".in" TEST_INPUT ${SRC})
    string(REPLACE ".cpp" ".out" TEST_OUTPUT ${SRC})
    target_compile_definitions(${BIN}_test PUBLIC TEST TEST_INPUT="${TEST_INPUT}" TEST_OUTPUT="${TEST_OUTPUT}")
endforeach (SRC ${APP_SOURCES})