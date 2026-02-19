cmake_minimum_required(VERSION 3.30)
project(debug_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(test_http src/launcher.cpp
        src/DebugSystem.cpp
        src/DebugSystem.h)
