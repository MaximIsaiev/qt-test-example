cmake_minimum_required(VERSION 3.26)
project(QtTestExample)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
    Core
    REQUIRED
)

add_executable(QtTestExample main.cpp)

add_subdirectory(smart)

target_link_libraries(QtTestExample
    Qt5::Core
    smartlib
)
