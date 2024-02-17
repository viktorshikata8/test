cmake_minimum_required(VERSION 3.10)
project(test
    VERSION 1.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PUBLIC
        src/main.cpp
        src/shapes.h
        src/shapes.cpp
)
