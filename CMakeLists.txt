cmake_minimum_required(VERSION 3.30)
project(debug_system VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME}
        src/debug_system.cpp
        include/debug_api.h
)

target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)