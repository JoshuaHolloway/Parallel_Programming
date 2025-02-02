set(CMAKE_CXX_COMPILER "/opt/intel/compilers_and_libraries_2018.1.163/linux/bin/intel64/icpc")
set(CMAKE_CXX_COMPILER_ARG1 "")
set(CMAKE_CXX_COMPILER_ID "Intel")
set(CMAKE_CXX_COMPILER_VERSION "18.0.1.20171018")
set(CMAKE_CXX_COMPILER_WRAPPER "")
set(CMAKE_CXX_STANDARD_COMPUTED_DEFAULT "11")
set(CMAKE_CXX_COMPILE_FEATURES "")
set(CMAKE_CXX98_COMPILE_FEATURES "")
set(CMAKE_CXX11_COMPILE_FEATURES "")
set(CMAKE_CXX14_COMPILE_FEATURES "")

set(CMAKE_CXX_PLATFORM_ID "Linux")
set(CMAKE_CXX_SIMULATE_ID "")
set(CMAKE_CXX_SIMULATE_VERSION "")

set(CMAKE_AR "/usr/bin/ar")
set(CMAKE_RANLIB "/usr/bin/ranlib")
set(CMAKE_LINKER "/usr/bin/ld")
set(CMAKE_COMPILER_IS_GNUCXX )
set(CMAKE_CXX_COMPILER_LOADED 1)
set(CMAKE_CXX_COMPILER_WORKS TRUE)
set(CMAKE_CXX_ABI_COMPILED TRUE)
set(CMAKE_COMPILER_IS_MINGW )
set(CMAKE_COMPILER_IS_CYGWIN )
if(CMAKE_COMPILER_IS_CYGWIN)
  set(CYGWIN 1)
  set(UNIX 1)
endif()

set(CMAKE_CXX_COMPILER_ENV_VAR "CXX")

if(CMAKE_COMPILER_IS_MINGW)
  set(MINGW 1)
endif()
set(CMAKE_CXX_COMPILER_ID_RUN 1)
set(CMAKE_CXX_IGNORE_EXTENSIONS inl;h;hpp;HPP;H;o;O;obj;OBJ;def;DEF;rc;RC)
set(CMAKE_CXX_SOURCE_FILE_EXTENSIONS C;M;c++;cc;cpp;cxx;mm;CPP)
set(CMAKE_CXX_LINKER_PREFERENCE 30)
set(CMAKE_CXX_LINKER_PREFERENCE_PROPAGATES 1)

# Save compiler ABI information.
set(CMAKE_CXX_SIZEOF_DATA_PTR "8")
set(CMAKE_CXX_COMPILER_ABI "ELF")
set(CMAKE_CXX_LIBRARY_ARCHITECTURE "x86_64-linux-gnu")

if(CMAKE_CXX_SIZEOF_DATA_PTR)
  set(CMAKE_SIZEOF_VOID_P "${CMAKE_CXX_SIZEOF_DATA_PTR}")
endif()

if(CMAKE_CXX_COMPILER_ABI)
  set(CMAKE_INTERNAL_PLATFORM_ABI "${CMAKE_CXX_COMPILER_ABI}")
endif()

if(CMAKE_CXX_LIBRARY_ARCHITECTURE)
  set(CMAKE_LIBRARY_ARCHITECTURE "x86_64-linux-gnu")
endif()

set(CMAKE_CXX_CL_SHOWINCLUDES_PREFIX "")
if(CMAKE_CXX_CL_SHOWINCLUDES_PREFIX)
  set(CMAKE_CL_SHOWINCLUDES_PREFIX "${CMAKE_CXX_CL_SHOWINCLUDES_PREFIX}")
endif()




set(CMAKE_CXX_IMPLICIT_LINK_LIBRARIES "imf;svml;irng;stdc++;m;ipgo;decimal;cilkrts;stdc++;irc;svml;c;irc_s;dl;c")
set(CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES "/opt/intel/clck/2018.1/lib/intel64;/opt/intel/compilers_and_libraries_2018.1.163/linux/ipp/lib/intel64;/opt/intel/compilers_and_libraries_2018.1.163/linux/compiler/lib/intel64_lin;/opt/intel/compilers_and_libraries_2018.1.163/linux/mkl/lib/intel64_lin;/opt/intel/compilers_and_libraries_2018.1.163/linux/tbb/lib/intel64/gcc4.7;/opt/intel/compilers_and_libraries_2018.1.163/linux/daal/lib/intel64_lin;/opt/intel/compilers_and_libraries_2018.1.163/linux/tbb/lib/intel64_lin/gcc4.4;/usr/lib/gcc/x86_64-linux-gnu/5;/usr/lib/x86_64-linux-gnu;/usr/lib;/lib/x86_64-linux-gnu;/lib64;/lib;/usr/lib/i386-linux-gnu")
set(CMAKE_CXX_IMPLICIT_LINK_FRAMEWORK_DIRECTORIES "")
