cmake_minimum_required(VERSION 2.6)
project (sudokuSolver)

message("Building target : "${PROJECT_NAME})
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
set(SOURCES
    src/sudoku.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories( sudokuSolver
PUBLIC ${PROJECT_SOURCE_DIR}/include
)
