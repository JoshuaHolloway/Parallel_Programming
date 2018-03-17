# Intel_Compiler_OpenVX_OpenCV_VTune
Usage of the Intel C++ compiler with CMake for building OpenVX+OpenCV program that can be profiled in VTune

Steps taken:

00. Compiling C++ program with linking a .h and second .cpp file using g++ with a shell script.

01. Compiling C++ program with linking a .h and second .cpp file using g++ with CMake.

02. Compiling C++ program with linking a .h and second .cpp file using Intel Compiler with CMake.

03. Compiling OpenCV program with linking a .h and second .cpp file using g++ with CMake.

04. Compiling OpenCV program with linking a .h and second .cpp file using Intel Compiler with CMake and VTune Profiling (only assembly seems to be mapping in VTune and not source).

Next steps for Intel Compiler:

05. Compiling OpenVX program with linking a .h and second .cpp file using Intel Compiler with CMake and VTune Profiling

06. Compiling OpenVX with OpenCV interoperability program with linking a .h and second .cpp file using Intel Compiler with CMake.

07. Compiling ORB-SLAM2 with Intel Compiler.

Profiling:

10. Compiling C++ program with VTune hotspot analysis with source code mapping working.

11. Compiling C++ program with VTune u-arch profiling with source code mapping working.

12. Compiling C++ program with Intel Parallel Advisor roofline profiling with source code mapping working.

13. Repeat 10-12 with OpenCV+OpenVX and ORB-SLAM2.

Debugging:

20. Compile C++ program with debugging with intel compiler and stepping through code in in Eclipse.
