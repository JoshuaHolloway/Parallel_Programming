# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc

# Include any dependencies generated for this target.
include CMakeFiles/sample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sample.dir/flags.make

CMakeFiles/sample.dir/main.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sample.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/main.cpp.o -c /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc/main.cpp

CMakeFiles/sample.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc/main.cpp > CMakeFiles/sample.dir/main.cpp.i

CMakeFiles/sample.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc/main.cpp -o CMakeFiles/sample.dir/main.cpp.s

CMakeFiles/sample.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/sample.dir/main.cpp.o.requires

CMakeFiles/sample.dir/main.cpp.o.provides: CMakeFiles/sample.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/sample.dir/build.make CMakeFiles/sample.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/sample.dir/main.cpp.o.provides

CMakeFiles/sample.dir/main.cpp.o.provides.build: CMakeFiles/sample.dir/main.cpp.o


CMakeFiles/sample.dir/Class.cpp.o: CMakeFiles/sample.dir/flags.make
CMakeFiles/sample.dir/Class.cpp.o: Class.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sample.dir/Class.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample.dir/Class.cpp.o -c /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc/Class.cpp

CMakeFiles/sample.dir/Class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample.dir/Class.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc/Class.cpp > CMakeFiles/sample.dir/Class.cpp.i

CMakeFiles/sample.dir/Class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample.dir/Class.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc/Class.cpp -o CMakeFiles/sample.dir/Class.cpp.s

CMakeFiles/sample.dir/Class.cpp.o.requires:

.PHONY : CMakeFiles/sample.dir/Class.cpp.o.requires

CMakeFiles/sample.dir/Class.cpp.o.provides: CMakeFiles/sample.dir/Class.cpp.o.requires
	$(MAKE) -f CMakeFiles/sample.dir/build.make CMakeFiles/sample.dir/Class.cpp.o.provides.build
.PHONY : CMakeFiles/sample.dir/Class.cpp.o.provides

CMakeFiles/sample.dir/Class.cpp.o.provides.build: CMakeFiles/sample.dir/Class.cpp.o


# Object files for target sample
sample_OBJECTS = \
"CMakeFiles/sample.dir/main.cpp.o" \
"CMakeFiles/sample.dir/Class.cpp.o"

# External object files for target sample
sample_EXTERNAL_OBJECTS =

sample: CMakeFiles/sample.dir/main.cpp.o
sample: CMakeFiles/sample.dir/Class.cpp.o
sample: CMakeFiles/sample.dir/build.make
sample: CMakeFiles/sample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable sample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sample.dir/build: sample

.PHONY : CMakeFiles/sample.dir/build

CMakeFiles/sample.dir/requires: CMakeFiles/sample.dir/main.cpp.o.requires
CMakeFiles/sample.dir/requires: CMakeFiles/sample.dir/Class.cpp.o.requires

.PHONY : CMakeFiles/sample.dir/requires

CMakeFiles/sample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sample.dir/clean

CMakeFiles/sample.dir/depend:
	cd /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc /home/josh/Desktop/test_intel_compiler/03_compile_with_Cmake_gcc/CMakeFiles/sample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sample.dir/depend

