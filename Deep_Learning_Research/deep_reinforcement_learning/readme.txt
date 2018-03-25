# Implementation of Principal Policy Optimization Deep Reinforcement Learning algorithm with Intel's Coach and Tensorflow

# Coach: 
$ source coach_env/bin/activate
$ python3 coach.py -r -p CartPole_PG


# OpenAI's PPO Algorithm:
## Blog:
https://blog.openai.com/openai-baselines-ppo/

## Github for Baselines:
https://github.com/openai/baselines

## OpenAI Gym with github and docs:
https://gym.openai.com/


# Intel Coach:
## Github:
https://github.com/NervanaSystems/coach

## Blog:
https://ai.intel.com/reinforcement-learning-coach-intel/

## Wiki:
http://coach.nervanasys.com/

## ==========================

## To install intel's coach and run the code:
$ python -V # Python 2.7 was the default version in successful install
$ git clone https://github.com/NervanaSystems/coach.git
$ cd coach

# Note - select no to neon due to a conflict with MKL
$ ./install.sh
$ source coach_env/bin/activate
$ python3 coach.py -r -p CartPole_PG



## ===========================

# First, i installed gym (I think this part can be skipped and you can go right to the Mujoco stuff below)

To install gyp seperately:
$ sudo apt-get install -y python-numpy python-dev cmake zlib1g-dev libjpeg-dev xvfb libav-tools xorg-dev python-opengl libboost-all-dev libsdl2-dev swig
$ git clone https://github.com/openai/gym.git
$ cd gym
$ sudo pip install -e .
$ sudo pip install "gym[atari]"
$ sudo python setup.py install

# cd to my reinforcement learning directory, then:
$ git clone https://github.com/openai/atari-py.git
$ cd atari_pi
$ make
$ export PYTHONPATH=/path/to/atari-py:$PYTHONPATH
$ python

## MUJOCO STUFFs

Mujoco: 
https://github.com/openai/mujoco-py

1. Obtain a 30-day free trial on the MuJoCo website or free license if you are a student. The license key will arrive in an email with your username and password.

2. Download the MuJoCo version 1.50 binaries for Linux, OSX, or Windows.

3  Unzip the downloaded mjpro150 directory into ~/.mujoco/mjpro150, and place your license key (the mjkey.txt file from your email) at ~/.mujoco/mjkey.txt.

# Step 3 is done as follows (after unzipping and retrieving the liscence file (LICENSE.txt and mjkey.txt == for some reason I have two == I just placed both in the specified directory to be safe)
$ mv mjpro150/ ~/.mujoco/mjpro150
$ mv mjkey.txt ~/.mujoco/mjpro150
$ mv LICENSE.txt ~/.mujoco/mjpro150


# Below is the info that was given to me when I signed up for a lisense for Mujoco. They also emailed me the two license files mensioned above.
MuJoCo Pro Trial License

Full name	josh hol
Email address	jhollow6@asu.edu
Computer id	LINUX_2NA6HHS7G1010S9E630_JK100YRP12RRTT215
IP address	71.223.227.145




After doing the above Mujoco stuff, I deleted the baselines folder and started from sratch:
$ git clone https://github.com/openai/baselines.git
$ cd baselines
$ pip install -e .

PermissionError: [Errno 13] Permission denied: '/usr/local/lib/python3.5/dist-packages/libpasteurize'



When I run pip install -e .
I get an error related to permissions.
But when I run it as:
sudo pip install -e .
I get this error:

Command "python setup.py egg_info" failed with error code 1 in /tmp/pip-build-3VEduH/mujoco-py/

# It appears as if shouldn't enter sudo in front of that command.
To try to avoid entering sudo, I have changed permissions so that all users can edit the files like so:
sudo chmod -R o+rwx /usr/local/lib/python3.5/dist-packages/libpasteurize
sudo chmod -R o+rwx /usr/local/bin/pasteurize
sudo chmod -R o+rwx /usr/local/bin

After that, having this error:
GL/osmesa.h: No such file or directory

Ran this to solve:
$ sudo apt-get install libosmesa6-dev

I received another error concerning permisions, so I ran the above "sudo chmod -R o+rwx" command on every directory that came up.  Ran it a few times.

# I then ran the following commands just placing the downloaded file from github on my desktop.
# https://github.com/openai/mujoco-py/issues/66
git clone https://github.com/openai/mujoco-py.git
cd mujoco-py
sudo apt-get update
sudo apt-get install libgl1-mesa-dev libgl1-mesa-glx libosmesa6-dev python3-pip python3-numpy python3-scipy
pip3 install -r requirements.txt
sudo python3 setup.py install


# After that, I cd'd to the ppo1 directory and ran:
$ python -m baselines.ppo1.run_mujoco



# Received an error for opencv cv2 python binding.
# Reinsstalled with opencv 3.4.1 with python 3 with contrib library:

sudo apt-get update
sudo apt-get upgrade

sudo apt-get install build-essential cmake pkg-config
sudo apt-get install libjpeg8-dev libtiff5-dev libjasper-dev libpng12-dev
sudo apt-get install libavcodec-dev libavformat-dev dlibswscale-dev libv4l-dev

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

cmake -D CMAKE_BUILD_TYPE=RELEASE \
    -D CMAKE_INSTALL_PREFIX=/usr/local \
    -D INSTALL_PYTHON_EXAMPLES=ON \
    -D INSTALL_C_EXAMPLES=OFF \
    -D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib-3.4.1/modules \
    -D PYTHON_EXECUTABLE=/usr/bin/python3.5 \
    -D BUILD_EXAMPLES=ON ..

# the number after -j means the compiler will use that number of logical cores on your CPU
make -j6
sudo make install
sudo ldconfig

# I saved the above in the main directory under filename build_openCV341.sh

# After that, I cd'd to the ppo1 directory and ran:
$ python -m baselines.ppo1.run_mujoco

#Experienced this error:
ERROR: Could not open activation key file /home/josh/.mujoco/mjkey.txt

# I placed the mjkey into /home/josh/.mujoco/mjpro150

# Made copy in /home/josh/.mujoco along with all the files in mjpro150

# Then, experienced this error:
gym.error.DependencyNotInstalled: Failed to load GLFW3 shared library.. (HINT: you need to install mujoco_py, and also perform the setup instructions here: https://github.com/openai/mujoco-py/.)

# Entered this (as described in the link provided in previous error):
$ LD_LIBRARY_PATH=$HOME/.mujoco/mjpro150/bin pip install mujoco-py
$ pip3 install -U 'mujoco-py<1.50.2,>=1.50.1'

# Did this:
$ cd ~/.mujoco
$ git clone https://github.com/openai/mujoco-py.git
$ cd mujoco-py
$ pip install -r requirements.txt
$ pip install -r requirements.dev.txt
$ python setup.py install

# And, finally, I did below (as described here: https://github.com/openai/mujoco-py/issues/157):
$ LD_LIBRARY_PATH=$HOME/.mujoco/mjpro150/bin

And ran:
$ python -m baselines.ppo1.run_mujoco

