cmake_minimum_required(VERSION 3.31)
project(
    MATRIX
    VERSION 0.0.1
    DESCRIPTION "Matrix class"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

add_executable(matrix_class)

set(sources
    src/main.cpp
    src/matrix.h
    src/matrix.cpp
)   
target_sources(matrix_class PRIVATE ${sources})

target_include_directories(matrix_class
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)