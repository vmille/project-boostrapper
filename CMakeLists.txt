cmake_minimum_required(VERSION 3.18)
project(project-boostrapper)
set(CMAKE_CXX_STANDARD 23)

find_package(catch2 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(test)