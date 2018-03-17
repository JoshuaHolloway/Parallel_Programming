readme.txt - Josh Holloway

# 04_compile_openCV_with_cmake_intel_vtune

I added the convolution code to main.cpp.  The conv example is found here:
https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/filter_2d/filter_2d.html

I followed the instructions from the readme from (02_compile_with_Cmake_intel) to use CCmake to change the compiler to Intel.

=========

$ source /opt/intel/compilers_and_libraries_2018/linux/bin/compilervars.sh intel64
$ source /opt/intel/parallel_studio_xe_2018.1.038/bin/psxevars.sh
$ mkdir build
$ cd build
$ ccmake ../
$ make

# c to configure

# t to toggle

# Set CMAKE_CXX_COMPILER to: 
	/opt/intel/compilers_and_libraries_2018.1.163/linux/bin/intel64/icpc
		-ENTER to mod
		-ENTER after making mod

# c to configure 
	-Takes a while

# Press e to exit when done config

# t to toggle out of advanced mode

# g to generate

# Now make
$ make

# Run:
./DisplayImage baboon.png 


=========

VTune:

$ source /opt/intel/vtune_amplifier/amplxe-vars.sh
$ amplxe-gui&

# Select new analysis and enter the following:

Application:
/home/josh/Desktop/Intel_Compiler_OpenVX_OpenCV_VTune/04_compile_openCV_with_cmake_intel_vtune/build/DisplayImage

Application Parameters:
/home/josh/Desktop/Intel_Compiler_OpenVX_OpenCV_VTune/04_compile_openCV_with_cmake_intel_vtune/build/baboon.png
