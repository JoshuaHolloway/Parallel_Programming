# Copyright Intel Corporation 2014
#
# To compile with the GNU* C/C++ compiler, creating an execution file with the
# extension ".gcc" for binary instrumentation, issue:
#
#   > make
#
# To compile with the Intel(R) C++ Compiler for Linux*, creating an execution
# file with the extension ".icc":
#
#   Source <path_to_compiler_bin>/compilervars.sh or iccvars.csh;
#
#   > make icc
#
# To compile with the Intel(R) C++ Compiler for Linux* with Intel(R) MKL library
# creating an executionfile with the extension ".mkl":
#
#   Source <path_to_compiler_bin>/compilervars.sh or iccvars.csh;
#
#   > make mkl
#
# To compile with the Intel(R) C++ Compiler for Linux to cross compile for the
# Intel(R) Xeon Phi(TM) coprocessor, creating an execution file with the
# extension ".mic":
#
#   Source <path_to_compiler_bin>/compilervars.sh intel64
#
#   > make mic
#
# To compile them all, use the source line from the Intel MIC architecture
# option above, then type:
#
#   > make all

SHELL = /bin/sh

PARAMODEL = -DUSE_THR	# Default parallelism using pthreads/Win threads
#PARAMODEL = -DUSE_OMP -fopenmp	# Use OpenMP for multithreading

INCLUDE_DIRS = -I/usr/local/include/opencv -I/usr/local/include


ICC     = icc
CCFLAGS  = -g -O2 -std=c++14 $(INCLUDE_DIRS)`pkg-config --cflags opencv`
#CXXFLAGS += -g -O2 -std=c++14 -DLINUX -Wall $(INCLUDE_DIRS) `pkg-config --cflags opencv`
LDFLAGS = `pkg-config --libs opencv`



OPTFLAGS = -xSSE3
# OPTFLAGS = -xHost -fno-alias
# add -DALIGNED to the multiply.c and matrix.cpp
LDFLAGS = -lpthread -lm

ICCFLAGS = $(CCFLAGS) $(PARAMODEL)-DICC -debug inline-debug-info #-vec-report3 -qopt-report -qopt-report-phase=vec

ICC_EXE = matrix.icc

srcdir = ../src

icc: $(ICC_EXE)

OBJS = matrix.o



matrix.icc: $(srcdir)/matrix.cpp
	$(ICC) $(ICCFLAGS) $(OPTFLAGS) -c $(srcdir)/matrix.cpp -D_LINUX
	$(ICC) $(ICCFLAGS) $(OBJS) -o $@ $(LDFLAGS)


# * Other names and brands may be claimed as the property of others.
