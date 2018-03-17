readme.txt - Josh Holloway

# 10_compile_with_Cmake_intel _VTune_source

# Documentation from From 02_compile_with_Cmake_intel:

Instructions from here:

Video descritbing how to use Intel Compiler (for windows - but still good - modifications are described in this document):
	https://www.youtube.com/watch?v=NtRO3y-X9iw

Getting started with intel c++ compiler:
	https://software.intel.com/en-us/get-started-with-cpp-compiler-18.0-for-linux-parallel-studio-xe-2018

Jason Turner description of how to use ccmake to change the compiler:
	https://www.youtube.com/watch?v=HPMvU64RUTY

#==============

# Not sure if need to run  compilervars.sh 
$ source /opt/intel/compilers_and_libraries_2018/linux/bin/compilervars.sh intel64
$ source /opt/intel/parallel_studio_xe_2018.1.038/bin/psxevars.sh
$ mkdir build
$ cd build
$ ccmake ../

# Press c to configure
# Press t to toggle

# Change CMAKE_CXX_COMPILER to /opt/intel/compilers_and_libraries_2018.1.163/linux/bin/intel64/icpc
	-Press ENTER to mod
	-Press ENTER after making mod

# c to configure 
	-Takes a while to configure

# After configuration is complete press e

# t to toggle out of advanced mode
# g to generate


# Now make
$ make

#====================================

Apparently compiling with the intel compiler automaticaly allows cilk to work as a header.

=================
=================
=================
=================

# New Documentation:

VTune:

$ source /opt/intel/vtune_amplifier/amplxe-vars.sh
$ amplxe-gui&

Select advanced hotspot analysis to get to source code.

====

Parallel Advisor:

https://software.intel.com/en-us/get-started-with-advisor-vectorization-advisor

Change build type in CMakeLists.txt to Release

Request full debug information (compiler and linker).
	Linux* OS command line: -g

Request moderate optimization.
	Linux* OS command line: -O2 or higher

Produce compiler diagnostics (necessary for version 15.0 of the Intel compiler; unnecessary for version 16.0 and higher).
	Linux* OS command line: -qopt-report=5

Enable vectorization
Linux* OS command line: -vec

$ source /opt/intel/advisor_2018.1.1.535164/advixe-vars.sh

