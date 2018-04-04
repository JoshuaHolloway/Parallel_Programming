MATLAB="/usr/local/MATLAB/R2018a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/josh/.matlab/R2018a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for mypredictCL" > mypredictCL_mex.mki
echo "CC=$CC" >> mypredictCL_mex.mki
echo "CFLAGS=$CFLAGS" >> mypredictCL_mex.mki
echo "CLIBS=$CLIBS" >> mypredictCL_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> mypredictCL_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> mypredictCL_mex.mki
echo "CXX=$CXX" >> mypredictCL_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> mypredictCL_mex.mki
echo "CXXLIBS=$CXXLIBS" >> mypredictCL_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> mypredictCL_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> mypredictCL_mex.mki
echo "LDFLAGS=$LDFLAGS" >> mypredictCL_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> mypredictCL_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> mypredictCL_mex.mki
echo "Arch=$Arch" >> mypredictCL_mex.mki
echo "LD=$LD" >> mypredictCL_mex.mki
echo OMPFLAGS= >> mypredictCL_mex.mki
echo OMPLINKFLAGS= >> mypredictCL_mex.mki
echo "EMC_COMPILER=gcc" >> mypredictCL_mex.mki
echo "EMC_CONFIG=optim" >> mypredictCL_mex.mki
"/usr/local/MATLAB/R2018a/bin/glnxa64/gmake" -j 1 -B -f mypredictCL_mex.mk
