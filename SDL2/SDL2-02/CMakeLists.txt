cmake_minimum_required(VERSION 3.17)
project(SDL2_02 C)

set(CMAKE_C_STANDARD 11)
link_libraries(SDL2)
add_executable(SDL2_02 main.c)