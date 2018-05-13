//#pragma once
// header.h
//-------------------------------------------------------------------
// OpenCV stuff:
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//-------------------------------------------------------------------
// CUDA stuff:
#include <device_launch_parameters.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <cuda.h>
#include <device_functions.h>
#include <cudnn.h>
//-------------------------------------------------------------------
// C++ stuff:
#include <iostream> 
//#include <fstream>
#include <string>
//#include <vector>
using std::cout;
using std::string;
//-------------------------------------------------------------------
// C and Windows stuff:
#include <windows.h>
#include <stdio.h>
//-------------------------------------------------------------------
// Declare Wrapper Function
int kernel_wrapper(const cv::Mat&);
