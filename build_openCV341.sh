sudo apt-get update
sudo apt-get upgrade

sudo apt-get install build-essential cmake pkg-config
sudo apt-get install libjpeg8-dev libtiff5-dev libjasper-dev libpng12-dev
sudo apt-get install libavcodec-dev 
sudo apt-get install libavformat-dev
sudo apt-get install libv4l-dev
sudo apt-get install libswscale-dev

sudo apt-get install libxvidcore-dev libx264-dev
sudo apt-get install libgtk-3-dev
sudo apt-get install libatlas-base-dev gfortran
sudo apt-get install python2.7-dev python3.5-dev
cd ~
wget -O opencv.zip https://github.com/Itseez/opencv/archive/3.4.1.zip
unzip opencv.zip
wget -O opencv_contrib.zip https://github.com/Itseez/opencv_contrib/archive/3.4.1.zip
unzip opencv_contrib.zip

pip install numpy
cd ~/opencv-3.4.1/
mkdir build
cd build

# SEE BOTTOM FOR BUILD WITH DEBUGGING SYMBOLS!!!
cmake -D CMAKE_BUILD_TYPE=RELEASE \
    -D CMAKE_INSTALL_PREFIX=/usr/local \
    -D INSTALL_PYTHON_EXAMPLES=ON \
    -D INSTALL_C_EXAMPLES=OFF \
    -D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib-3.4.1/modules \
    -D PYTHON_EXECUTABLE=/usr/bin/python3.5 \
    -D BUILD_EXAMPLES=ON ..

make -j6
sudo make install
sudo ldconfig


=======================
To build with debugging symbols (http://unixnme.blogspot.com/2016/11/how-to-compile-opencv-with-debugging.html), 
do this instead:
cmake -DCMAKE_BUILD_TYPE:STRING=RelWithDebInfo \
    -D CMAKE_INSTALL_PREFIX=/usr/local \
    -D INSTALL_PYTHON_EXAMPLES=ON \
    -D INSTALL_C_EXAMPLES=OFF \
    -D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib-3.4.1/modules \
    -D PYTHON_EXECUTABLE=/usr/bin/python3.5 \
    -D BUILD_EXAMPLES=ON ..
