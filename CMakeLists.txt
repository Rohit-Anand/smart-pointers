cmake_minimum_required(VERSION 3.8)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")

project(StdLibImpl)

# Add source to this project's executable.
add_subdirectory (src)