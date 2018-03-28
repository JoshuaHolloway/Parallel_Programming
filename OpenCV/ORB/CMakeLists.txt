# Modify this to be like other

# Modified
cmake_minimum_required(VERSION 3.0)

# Added
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14") # NEED TO CHANGE OPTIMIZATION FLAGS FOR VTUNE!!!!
SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -g")
#SET(CMAKE_CXX_COMPILER "icpc")



# Same
project( orb )
find_package( OpenCV REQUIRED )

# Modified
add_executable(
	orb
	orb.cpp
)

#Same
target_link_libraries( orb ${OpenCV_LIBS} )
