cmake_minimum_required(VERSION 3.17)
project(problem_solving_cpp)

set(CMAKE_CXX_STANDARD 17)

file( GLOB SOURCES codeground/**/*.cpp )
file( GLOB UTILS utils/*.cpp )

foreach( SRC ${SOURCES} )
    message(${SRC})
    get_filename_component( BIN ${SRC} NAME_WE )
    add_executable( ${BIN} ${SRC})
endforeach( SRC ${APP_SOURCES} )