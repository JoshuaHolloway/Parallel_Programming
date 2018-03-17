# Run the Intel Compiler script
source /opt/intel/compilers_and_libraries_2018/linux/bin/compilervars.sh intel64
source /opt/intel/parallel_studio_xe_2018.1.038/bin/psxevars.sh # Not sure needed
source /opt/intel/advisor_2018.1.1.535164/advixe-vars.sh # For advisor
source /opt/intel/vtune_amplifier/amplxe-vars.sh # For V-tune

#Compile with Intel C-Compiler (use icpc for C++)
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=icpc -DCMAKE_CC_COMPILER=icc
make -j

# Open Advisor
#advixe-gui&

# Open VTune
#amplxe-gui&
