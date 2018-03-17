# Modify this to be like other

# Modified
cmake_minimum_required(VERSION 3.0)

# Added
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Same
project( DisplayImage )
find_package( OpenCV REQUIRED )

# Modified
add_executable( 
	DisplayImage 
	main.cpp     
	Class.h
    	Class.cpp
)

#Same
target_link_libraries( DisplayImage ${OpenCV_LIBS} )
