sudo apt-get clean
sudo apt-get update
sudo apt-get upgrade
sudo apt install mesa-utils
sudo apt-get install libglew-dev
sudo apt-get install cmake

sudo apt-get install libpython2.7-dev
sudo apt-get install python-setuptools python-dev build-essential
sudo easy_install pip
sudo pip install numpy
sudo pip install pyopengl
sudo apt-get install python-pil
sudo pip install pybind11
sudo apt-get install ffmpeg libavcodec-dev libavutil-dev libavformat-dev libswscale-dev
sudo apt-get install libdc1394-22-dev libraw1394-dev

sudo apt-get install libjpeg-dev libpng12-dev libtiff5-dev libopenexr-dev
cd ~

mkdir libs_josh
cd libs_josh
sudo apt-get install git

git clone https://github.com/stevenlovegrove/Pangolin.git
cd Pangolin
mkdir build
cd build
cmake ..
cmake --build .
