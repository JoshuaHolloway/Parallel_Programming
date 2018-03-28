Istall OpenCL - when installing the two pre-reqs from the scripts in the installation instructions from the intel sdk downloads page, the second script does not run.  So I simply opened up the script, and ran each of the commands manually. There is an if-else statement that makes the script perform different  tasks for Yocto and Ubuntu. So I just extracted the parts pertaining to Ubuntu:

  sudo su
  apt-add-repository ppa:webupd8team/java
  apt-get update
  apt-get install oracle-java8-installer
  apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys     3FA7E0328081BFF6A14DA29AA6A19B38D3D831EF
  echo "deb http://download.mono-project.com/repo/ubuntu stable-xenial main" | sudo tee /etc/apt/sources.list.d/mono-official-stable.list
  sudo apt-get update
  curl -O http://launchpadlibrarian.net/201330288/libicu52_52.1-8_amd64.deb
  dpkg -i libicu52_52.1-8_amd64.deb
  apt-get update
  apt-get install mono-complete ca-certificates-mono
  apt-get install dkms
  apt-get install lsb-core

Summary of opencl install:
Run the script: install_OCL_driver.sh
Then, the second script, is the one that wouldn’t run.
Then, i installed the actual SDK.

Note that they have a test python script that tells you if the stuff installed correctly: (sys_analyzer_linux.py)
$ python2 sys_analyzer_linux.py -v

After that, do this:
$ tar xvfz intel_sdk_for_opencl_2017_7.0.0.2568_x64.gz 
$ cd intel_sdk_for_opencl_2017_7.0.0.2568_x64/
$ sudo ./install.sh

I then ran created a .cl file and placed the following contents in it and ran thi:

    ioc64 -input=simpleAdd.cl -asm

Contents:
__kernel void simpleAdd(
                       __global int *pA,                      
                       __global int *pB,                      
                       __global int *pC)                      
{                                                              
    const int id = get_global_id(0);                                 
    pC[id] = pA[id] + pB[id];                                 
}
