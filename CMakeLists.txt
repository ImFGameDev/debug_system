cmake_minimum_required(VERSION 3.30)
project(debug_system VERSION 1.0)

add_library(${PROJECT_NAME}
        src/debug_system.cpp
)

target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)