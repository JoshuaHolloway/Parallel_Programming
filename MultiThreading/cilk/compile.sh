# Run the Intel Compiler script
source /opt/intel/compilers_and_libraries_2018/linux/bin/compilervars.sh intel64
source /opt/intel/parallel_studio_xe_2018.1.038/bin/psxevars.sh # Not sure needed

#icl main.cpp
icl /Qvec-report2 main.cpp
