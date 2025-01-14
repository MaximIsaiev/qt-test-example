cmake_minimum_required(VERSION 3.7)

project(concurrentlib LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)

add_library(${PROJECT_NAME} STATIC
    include/concurrent.h
    src/concurrent.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt5::Core
)
