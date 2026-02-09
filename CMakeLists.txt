cmake_minimum_required(VERSION 3.22.1)
project(flappyBird)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

add_executable(flappybird src/main.cpp)

target_link_libraries(flappybird PRIVATE raylib)
