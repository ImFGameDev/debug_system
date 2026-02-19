cmake_minimum_required(VERSION 3.30)
project(debug_system VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(debug_system
        src/DebugSystem.cpp
        src/DebugSystem.h)
