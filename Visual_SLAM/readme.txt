This directory has ORB-SLAM2 with modifications.

$ ./Examples/Monocular/mono_kitti Vocabulary/ORBvoc.txt Examples/Monocular/KITTI00-02.yaml /home/josh/Desktop/00

VTune:
Application: /home/josh/Desktop/Parallel_Vision_Research/Visual_SLAM/orb_slam/Examples/Monocular/mono_kitti
Parameters: Vocabulary/ORBvoc.txt Examples/Monocular/KITTI00-02.yaml /home/josh/Desktop/00

The link to the 21GB Grayscale Kitti database dowload is here:
http://kitti.is.tue.mpg.de/kitti/data_odometry_gray.zip

Install described below:

First, place Eigen 3.2.10 (named eigen in this directory) in ~/
Then, run this for eigen:
$ sudo apt-get install libeigen3-dev

To build for Ubuntu 16.04 run the following scripts:

# Pangolin:
$ sudo ./pangolin_build_josh.sh

# The following script installs openCV 3.2 with the contrib library
# NOTE - Need to enter each command manually for python bindings to work.
$ sudo ./opencv_build_josh.sh 

# ======================================================================================
# Grab the ORB-SLAM2 code:
$ git clone https://github.com/raulmur/ORB_SLAM2.git ORB_SLAM2
$ cd ORB_SLAM2
$ sudo chmod +x build.sh
$ sudo ./build.sh


# ======================================================================================

NOTE - Running the opencv script results in the rather vanilla setup as described below.

-- General configuration for OpenCV 3.2.0 =====================================
--   Version control:               unknown
-- 
--   Extra modules:
--     Location (extra):            /home/josh/opencv_contrib-3.2.0/modules
--     Version control (extra):     unknown
-- 
--   Platform:
--     Timestamp:                   2018-03-23T20:02:49Z
--     Host:                        Linux 4.13.0-36-generic x86_64
--     CMake:                       3.5.1
--     CMake generator:             Unix Makefiles
--     CMake build tool:            /usr/bin/make
--     Configuration:               RELEASE
-- 
--   C/C++:
--     Built as dynamic libs?:      YES
--     C++ Compiler:                /usr/bin/c++  (ver 5.4.0)
--     C++ flags (Release):         -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wno-narrowing -Wno-delete-non-virtual-dtor -Wno-comment -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -mno-avx -msse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -ffunction-sections -fvisibility=hidden -fvisibility-inlines-hidden -O3 -DNDEBUG  -DNDEBUG
--     C++ flags (Debug):           -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wno-narrowing -Wno-delete-non-virtual-dtor -Wno-comment -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -mno-avx -msse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -ffunction-sections -fvisibility=hidden -fvisibility-inlines-hidden -g  -O0 -DDEBUG -D_DEBUG
--     C Compiler:                  /usr/bin/cc
--     C flags (Release):           -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wundef -Winit-self -Wpointer-arith -Wshadow -Wno-narrowing -Wno-comment -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -mno-avx -msse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -ffunction-sections -fvisibility=hidden -O3 -DNDEBUG  -DNDEBUG
--     C flags (Debug):             -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wundef -Winit-self -Wpointer-arith -Wshadow -Wno-narrowing -Wno-comment -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -mno-avx -msse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -ffunction-sections -fvisibility=hidden -g  -O0 -DDEBUG -D_DEBUG
--     Linker flags (Release):
--     Linker flags (Debug):
--     ccache:                      NO
--     Precompiled headers:         YES
--     Extra dependencies:          /usr/lib/x86_64-linux-gnu/libpng.so /usr/lib/x86_64-linux-gnu/libz.so /usr/lib/x86_64-linux-gnu/libtiff.so /usr/lib/x86_64-linux-gnu/libjasper.so /usr/lib/x86_64-linux-gnu/libjpeg.so /usr/lib/x86_64-linux-gnu/libImath.so /usr/lib/x86_64-linux-gnu/libIlmImf.so /usr/lib/x86_64-linux-gnu/libIex.so /usr/lib/x86_64-linux-gnu/libHalf.so /usr/lib/x86_64-linux-gnu/libIlmThread.so gtk-3 gdk-3 pangocairo-1.0 pango-1.0 atk-1.0 cairo-gobject cairo gdk_pixbuf-2.0 gio-2.0 gobject-2.0 glib-2.0 gthread-2.0 gstbase-1.0 gstreamer-1.0 gstvideo-1.0 gstapp-1.0 gstriff-1.0 gstpbutils-1.0 dc1394 avcodec-ffmpeg avformat-ffmpeg avutil-ffmpeg swscale-ffmpeg dl m pthread rt
--     3rdparty dependencies:       libwebp libprotobuf
-- 
--   OpenCV modules:
--     To be built:                 core flann imgproc ml photo reg surface_matching video dnn freetype fuzzy imgcodecs shape videoio highgui objdetect plot superres ts xobjdetect xphoto bgsegm bioinspired dpm face features2d line_descriptor saliency text calib3d ccalib datasets rgbd stereo tracking videostab xfeatures2d ximgproc aruco optflow phase_unwrapping stitching structured_light
--     Disabled:                    world contrib_world
--     Disabled by dependency:      -
--     Unavailable:                 cudaarithm cudabgsegm cudacodec cudafeatures2d cudafilters cudaimgproc cudalegacy cudaobjdetect cudaoptflow cudastereo cudawarping cudev java python2 python3 viz cnn_3dobj cvv hdf matlab sfm
-- 
--   GUI: 
--     QT:                          NO
--     GTK+ 3.x:                    YES (ver 3.18.9)
--     GThread :                    YES (ver 2.48.2)
--     GtkGlExt:                    NO
--     OpenGL support:              NO
--     VTK support:                 NO
-- 
--   Media I/O: 
--     ZLib:                        /usr/lib/x86_64-linux-gnu/libz.so (ver 1.2.8)
--     JPEG:                        /usr/lib/x86_64-linux-gnu/libjpeg.so (ver )
--     WEBP:                        build (ver 0.3.1)
--     PNG:                         /usr/lib/x86_64-linux-gnu/libpng.so (ver 1.2.54)
--     TIFF:                        /usr/lib/x86_64-linux-gnu/libtiff.so (ver 42 - 4.0.6)
--     JPEG 2000:                   /usr/lib/x86_64-linux-gnu/libjasper.so (ver 1.900.1)
--     OpenEXR:                     /usr/lib/x86_64-linux-gnu/libImath.so /usr/lib/x86_64-linux-gnu/libIlmImf.so /usr/lib/x86_64-linux-gnu/libIex.so /usr/lib/x86_64-linux-gnu/libHalf.so /usr/lib/x86_64-linux-gnu/libIlmThread.so (ver 2.2.0)
--     GDAL:                        NO
--     GDCM:                        NO
-- 
--   Video I/O:
--     DC1394 1.x:                  NO
--     DC1394 2.x:                  YES (ver 2.2.4)
--     FFMPEG:                      YES
--       avcodec:                   YES (ver 56.60.100)
--       avformat:                  YES (ver 56.40.101)
--       avutil:                    YES (ver 54.31.100)
--       swscale:                   YES (ver 3.1.101)
--       avresample:                NO
--     GStreamer:                   
--       base:                      YES (ver 1.8.3)
--       video:                     YES (ver 1.8.3)
--       app:                       YES (ver 1.8.3)
--       riff:                      YES (ver 1.8.3)
--       pbutils:                   YES (ver 1.8.3)
--     OpenNI:                      NO
--     OpenNI PrimeSensor Modules:  NO
--     OpenNI2:                     NO
--     PvAPI:                       NO
--     GigEVisionSDK:               NO
--     Aravis SDK:                  NO
--     UniCap:                      NO
--     UniCap ucil:                 NO
--     V4L/V4L2:                    NO/YES
--     XIMEA:                       NO
--     Xine:                        NO
--     gPhoto2:                     NO
-- 
--   Parallel framework:            pthreads
-- 
--   Other third-party libraries:
--     Use IPP:                     9.0.1 [9.0.1]
--          at:                     /home/josh/opencv-3.2.0/build/3rdparty/ippicv/ippicv_lnx
--     Use IPP Async:               NO
--     Use VA:                      NO
--     Use Intel VA-API/OpenCL:     NO
--     Use Lapack:                  NO
--     Use Eigen:                   NO
--     Use Cuda:                    NO
--     Use OpenCL:                  YES
--     Use OpenVX:                  NO
--     Use custom HAL:              NO
-- 
--   OpenCL:                        <Dynamic loading of OpenCL library>
--     Include path:                /home/josh/opencv-3.2.0/3rdparty/include/opencl/1.2
--     Use AMDFFT:                  NO
--     Use AMDBLAS:                 NO
-- 
--   Python 2:
--     Interpreter:                 NO
-- 
--   Python 3:
--     Interpreter:                 NO
-- 
--   Python (for build):            NO
-- 
--   Java:
--     ant:                         NO
--     JNI:                         NO
--     Java wrappers:               NO
--     Java tests:                  NO
-- 
--   Matlab:                        Matlab not found or implicitly disabled
-- 
--   Documentation:
--     Doxygen:                     NO
-- 
--   Tests and samples:
--     Tests:                       YES
--     Performance tests:           YES
--     C/C++ Examples:              YES
-- 
--   Install path:                  /usr/local
-- 
--   cvconfig.h is in:              /home/josh/opencv-3.2.0/build
-- ------------------------------------------------------------
