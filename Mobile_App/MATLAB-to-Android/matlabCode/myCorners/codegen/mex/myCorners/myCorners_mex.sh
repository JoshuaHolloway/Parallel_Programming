MATLAB="/usr/local/MATLAB/R2018a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/josh/.matlab/R2018a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for myCorners" > myCorners_mex.mki
echo "CC=$CC" >> myCorners_mex.mki
echo "CFLAGS=$CFLAGS" >> myCorners_mex.mki
echo "CLIBS=$CLIBS" >> myCorners_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> myCorners_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> myCorners_mex.mki
echo "CXX=$CXX" >> myCorners_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> myCorners_mex.mki
echo "CXXLIBS=$CXXLIBS" >> myCorners_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> myCorners_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> myCorners_mex.mki
echo "LDFLAGS=$LDFLAGS" >> myCorners_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> myCorners_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> myCorners_mex.mki
echo "Arch=$Arch" >> myCorners_mex.mki
echo "LD=$LD" >> myCorners_mex.mki
echo OMPFLAGS= >> myCorners_mex.mki
echo OMPLINKFLAGS= >> myCorners_mex.mki
echo "EMC_COMPILER=gcc" >> myCorners_mex.mki
echo "EMC_CONFIG=optim" >> myCorners_mex.mki
"/usr/local/MATLAB/R2018a/bin/glnxa64/gmake" -j 1 -B -f myCorners_mex.mk
