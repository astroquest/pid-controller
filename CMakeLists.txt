cmake_minimum_required(VERSION 3.27.0)
project(PidController)

set(
    SOURCES
    src/pid.cpp
    src/pid.hpp
    test/main.cpp
    test/simulation/model.cpp
    test/simulation/model.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
