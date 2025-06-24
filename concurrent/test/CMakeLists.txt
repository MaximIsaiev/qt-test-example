project(concurrenttest LANGUAGES CXX)

find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

enable_testing(true)

add_executable(${PROJECT_NAME} concurrenttest.cpp
    concurrenttest.h)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt5::Test
    concurrentlib
)
