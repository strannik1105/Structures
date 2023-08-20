cmake_minimum_required(VERSION 3.25)
project(Structures C)

set(CMAKE_C_STANDARD 23)

add_executable(Structures main.c)

add_subdirectory(algorithms)
target_link_libraries(Structures algorithms)