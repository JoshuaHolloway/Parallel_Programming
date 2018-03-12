readme.txt - Josh Holloway

# How to use CMake to compile an OpenCV program


Instructions from here:
https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_gcc_cmake/linux_gcc_cmake.html

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

Run the exectuable:
$ ./sample
