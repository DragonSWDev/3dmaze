cmake_minimum_required(VERSION 2.6)
project(maze3d)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

set(MAZE3D_SOURCES main.cpp Game.cpp Map.cpp MeshCombiner/CMeshCombiner.cpp MazeGenerator.cpp)
set (CMAKE_CXX_FLAGS "-Wall -pedantic")
set (CMAKE_BUILD_TYPE "Release")

add_executable(maze3d ${MAZE3D_SOURCES})

TARGET_LINK_LIBRARIES(maze3d Irrlicht)

install(TARGETS maze3d RUNTIME DESTINATION bin)
