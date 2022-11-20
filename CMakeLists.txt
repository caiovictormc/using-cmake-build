cmake_minimum_required(VERSION 3.23)
project(using_cmake
        LANGUAGES CXX
        VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory("dependencies")
add_subdirectory("src")
