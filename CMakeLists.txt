cmake_minimum_required(VERSION 2.6)
project(maze3d)

add_executable(maze3d main.cpp)

install(TARGETS maze3d RUNTIME DESTINATION bin)
