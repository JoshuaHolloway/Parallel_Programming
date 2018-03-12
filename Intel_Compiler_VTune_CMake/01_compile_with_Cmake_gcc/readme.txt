readme.txt - Josh Holloway

# How to use CMake to generate the makefile
# Tthis is a continuation of the project found in the folder 01_compile_with_make_gcc

Instructions from here:
https://www.youtube.com/watch?v=elycr5wi9_g


# Create a file named CMakeLists.txt with the following contents:

cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(sample)

add_executable(
    sample
    main.cpp
    Class.h
    Class.cpp
)


#================================
Produce the makefile by running:
$ cmake .
$ make

Run the exectuable:
$ ./sample
