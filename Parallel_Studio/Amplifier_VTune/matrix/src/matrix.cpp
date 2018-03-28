/*
    Copyright 2005-2013 Intel Corporation.  All Rights Reserved.

    The source code contained or described herein and all documents related
    to the source code ("Material") are owned by Intel Corporation or its
    suppliers or licensors.  Title to the Material remains with Intel
    Corporation or its suppliers and licensors.  The Material is protected
    by worldwide copyright laws and treaty provisions.  No part of the
    Material may be used, copied, reproduced, modified, published, uploaded,
    posted, transmitted, distributed, or disclosed in any way without
    Intel's prior express written permission.

    No license under any patent, copyright, trade secret or other
    intellectual property right is granted to or conferred upon you by
    disclosure or delivery of the Materials, either expressly, by
    implication, inducement, estoppel or otherwise.  Any license under such
    intellectual property rights must be express and approved by Intel in
    writing.
*/

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <stdlib.h>
	#ifdef ICC // The ICC is defined (by default) for enabling Intel Compiler specific headers and calls
	#include <immintrin.h>
	#endif
#endif
#include <stdio.h>
#include <time.h>
#include <malloc.h>

#include "multiply.h"











#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/core/ocl.hpp>



using std::cout;
using std::cerr;
using std::vector;
using std::string;

using cv::Mat;
using cv::Point2f;
using cv::KeyPoint;
using cv::Scalar;
using cv::Ptr;

using cv::FastFeatureDetector;
using cv::SimpleBlobDetector;

using cv::DMatch;
using cv::BFMatcher;
using cv::DrawMatchesFlags;
using cv::Feature2D;
using cv::ORB;
using cv::BRISK;
using cv::AKAZE;
using cv::KAZE;


using cv::xfeatures2d::BriefDescriptorExtractor;
using cv::xfeatures2d::SURF;
using cv::xfeatures2d::SIFT;
using cv::xfeatures2d::DAISY;
using cv::xfeatures2d::FREAK;

const double kDistanceCoef = 4.0;
const int kMaxMatchingSize = 50;

inline void detect_and_compute(string type, Mat& img, vector<KeyPoint>& kpts, Mat& desc) {
    if (type.find("fast") == 0) {
        type = type.substr(4);
        Ptr<FastFeatureDetector> detector = FastFeatureDetector::create(10, true);
        detector->detect(img, kpts);
    }
    if (type.find("blob") == 0) {
        type = type.substr(4);
        Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create();
        detector->detect(img, kpts);
    }
    if (type == "surf") {
        Ptr<Feature2D> surf = SURF::create(800.0);
        surf->detectAndCompute(img, Mat(), kpts, desc);
    }
    if (type == "sift") {
        Ptr<Feature2D> sift = SIFT::create();
        sift->detectAndCompute(img, Mat(), kpts, desc);
    }
    if (type == "orb") {
        Ptr<ORB> orb = ORB::create();
        orb->detectAndCompute(img, Mat(), kpts, desc);
    }
    if (type == "brisk") {
        Ptr<BRISK> brisk = BRISK::create();
        brisk->detectAndCompute(img, Mat(), kpts, desc);
    }
    if (type == "kaze") {
        Ptr<KAZE> kaze = KAZE::create();
        kaze->detectAndCompute(img, Mat(), kpts, desc);
    }
    if (type == "akaze") {
        Ptr<AKAZE> akaze = AKAZE::create();
        akaze->detectAndCompute(img, Mat(), kpts, desc);
    }
    if (type == "freak") {
        Ptr<FREAK> freak = FREAK::create();
        freak->compute(img, kpts, desc);
    }
    if (type == "daisy") {
        Ptr<DAISY> daisy = DAISY::create();
        daisy->compute(img, kpts, desc);
    }
    if (type == "brief") {
        Ptr<BriefDescriptorExtractor> brief = BriefDescriptorExtractor::create(64);
        brief->compute(img, kpts, desc);
    }
}

/*
typedef unsigned long long  UINT64;

double TRIP_COUNT = (double)NUM * (double)NUM * (double)NUM;
int FLOP_PER_ITERATION = 2; // basic matrix multiplication

extern int getCPUCount();
extern double getCPUFreq();

// routine to initialize an array with data
void init_arr(TYPE row, TYPE col, TYPE off, TYPE a[][NUM])
{
  int i,j;

  for (i=0; i< NUM;i++) {
    for (j=0; j<NUM;j++) {
      a[i][j] = row*i+col*j+off;
    }
  }
}

// routine to print out contents of small arrays
void print_arr(char *name, TYPE array[][NUM])
{
  int i,j;

  printf("\n%s\n", name);
  for (i=0;i<NUM;i++){
    for (j=0;j<NUM;j++) {
      printf("%g\t",array[i][j]);
    }
    printf("\n"); fflush(stdout);
  }
}
*/
inline void match(string type, Mat& desc1, Mat& desc2, vector<DMatch>& matches) {
    matches.clear();
    if (type == "bf") {
        BFMatcher desc_matcher(cv::NORM_L2, true);
        desc_matcher.match(desc1, desc2, matches, Mat());
    }
    if (type == "knn") {
        BFMatcher desc_matcher(cv::NORM_L2, true);
        vector< vector<DMatch> > vmatches;
        desc_matcher.knnMatch(desc1, desc2, vmatches, 1);
        for (int i = 0; i < static_cast<int>(vmatches.size()); ++i) {
            if (!vmatches[i].size()) {
                continue;
            }
            matches.push_back(vmatches[i][0]);
        }
    }
    std::sort(matches.begin(), matches.end());
    while (matches.front().distance * kDistanceCoef < matches.back().distance) {
        matches.pop_back();
    }
    while (matches.size() > kMaxMatchingSize) {
        matches.pop_back();
    }
}

inline void findKeyPointsHomography(vector<KeyPoint>& kpts1, vector<KeyPoint>& kpts2,
        vector<DMatch>& matches, vector<char>& match_mask) {
    if (static_cast<int>(match_mask.size()) < 3) {
        return;
    }
    vector<Point2f> pts1;
    vector<Point2f> pts2;
    for (int i = 0; i < static_cast<int>(matches.size()); ++i) {
        pts1.push_back(kpts1[matches[i].queryIdx].pt);
        pts2.push_back(kpts2[matches[i].trainIdx].pt);
    }
    findHomography(pts1, pts2, cv::RANSAC, 4, match_mask);
}

int main(int argc, char** argv) {



	if (argc != 5) {
			cerr << "\nError: wrong (you had: " << argc << ") number of arguments (should be 5).\n";
			cerr    << "\nExample 16-2. 2D Feature detectors and 2D Extra Features framework\n\n"
							<< "Use:\n" << argv[0] << " <descriptors_type> <matching_algirthm> "
							<< "<path/image_file1> <path/image_file2>\n"
							<< "To run this demo\n\n"
							<< "Program expects at least four arguments:\n"
							<< "  - descriptors type (\"surf\", \"sink\", \"orb\", \"brisk\",\n"
							<< "       \"kaze\", \"akaze\", \"freak\", \"daisy\", \"brief\").\n"
							<< "       For \"brief\", \"freak\" and \"daisy\" you also need a prefix\n"
							<< "       that is either \"blob\" or \"fast\" (e.g. \"fastbrief\", "
							<< "\"blobdaisy\")\n"
							<< "  - match algorithm (\"bf\", \"knn\")\n"
							<< "  - path to the object image file\n"
							<< "  - path to the scene image file\n\n"
							<< "Examples:\n"
							<< argv[0] << " surf knn ../box.png ../box_in_scene.png\n"
							<< argv[0] << " fastfreak bf ../box.png ../box_in_scene.png\n"
							<< "\nNOTE: Not all of these methods are free, check licensing conditions!\n\n"
							<< std::endl;
			exit(1);
	}

	string desc_type(argv[1]);
	string match_type(argv[2]);

	string img_file1(argv[3]);
	string img_file2(argv[4]);

	Mat img1 = cv::imread(img_file1, CV_LOAD_IMAGE_COLOR);
	//Mat img2 = cv::imread(img_file2, CV_LOAD_IMAGE_COLOR);
















	/*
#ifdef WIN32
	clock_t start=0.0, stop=0.0;
#else // Pthreads
	double start=0.0, stop=0.0;
	struct timeval  before, after;
#endif
	double secs;
   	double flops;
	double mflops;

	char *buf1, *buf2, *buf3, *buf4;
	char *addr1, *addr2, *addr3, *addr4;
	array *a, *b, *c, *t;
	int Offset_Addr1=128, Offset_Addr2=192, Offset_Addr3=0,Offset_Addr4=64;

// malloc arrays space
// Define ALIGNED in the preprocessor
// Also add '/Oa' for Windows and '-fno-alias' for Linux
#ifdef ALIGNED

#ifdef WIN32
#ifdef ICC
	buf1 = _mm_malloc((sizeof (double))*NUM*NUM, 64);
	buf2 = _mm_malloc((sizeof (double))*NUM*NUM, 64);
	buf3 = _mm_malloc((sizeof (double))*NUM*NUM, 64);
	buf4 = _mm_malloc((sizeof (double))*NUM*NUM, 64);
#else
	buf1 = _aligned_malloc((sizeof (double))*NUM*NUM, 64);
	buf2 = _aligned_malloc((sizeof (double))*NUM*NUM, 64);
	buf3 = _aligned_malloc((sizeof (double))*NUM*NUM, 64);
	buf4 = _aligned_malloc((sizeof (double))*NUM*NUM, 64);
#endif //ICC
#else // WIN32
	buf1 = _mm_malloc((sizeof (double))*NUM*NUM, 64);
	buf2 = _mm_malloc((sizeof (double))*NUM*NUM, 64);
	buf3 = _mm_malloc((sizeof (double))*NUM*NUM, 64);
	buf4 = _mm_malloc((sizeof (double))*NUM*NUM, 64);
#endif //WIN32
	addr1 = buf1;
	addr2 = buf2;
	addr3 = buf3;
	addr4 = buf4;

#else //!ALIGNED
	buf1 = (char *) malloc(NUM*NUM*(sizeof (double))+1024);
	printf("Addr of buf1 = %p\n",buf1); fflush(stdout);
	addr1 = buf1 + 256 - ((UINT64)buf1%256) + (UINT64)Offset_Addr1;
	printf("Offs of buf1 = %p\n",addr1); fflush(stdout);

	buf2 = (char *) malloc(NUM*NUM*(sizeof (double))+1024);
	printf("Addr of buf2 = %p\n",buf2); fflush(stdout);
	addr2 = buf2 + 256 - ((UINT64)buf2%256) + (UINT64)Offset_Addr2;
	printf("Offs of buf2 = %p\n",addr2); fflush(stdout);

	buf3 = (char *) malloc(NUM*NUM*(sizeof (double))+1024);
	printf("Addr of buf3 = %p\n",buf3); fflush(stdout);
	addr3 = buf3 + 256 - ((UINT64)buf3%256) + (UINT64)Offset_Addr3;
	printf("Offs of buf3 = %p\n",addr3); fflush(stdout);

	buf4 = (char *) malloc(NUM*NUM*(sizeof (double))+1024);
	printf("Addr of buf4 = %p\n",buf4); fflush(stdout);
	addr4 = buf4 + 256 - ((UINT64)buf4%256) + (UINT64)Offset_Addr4;
	printf("Offs of buf4 = %p\n",addr4); fflush(stdout);

#endif //ALIGNED

	a = (array *) addr1;
	b = (array *) addr2;
	c = (array *) addr3;
	t = (array *) addr4;

// initialize the arrays with data
	init_arr(3,-2,1,a);
	init_arr(-2,1,3,b);

	// Printing model parameters
	GetModelParams(0, 0, 1);

// start timing the matrix multiply code
#ifdef WIN32
	start = clock();
#else
	#ifdef ICC
	start = (double)_rdtsc();
	#else
	gettimeofday(&before, NULL);
	#endif
#endif

	ParallelMultiply(NUM, a, b, c, t);

#ifdef WIN32
	stop = clock();
	secs = ((double)(stop - start)) / CLOCKS_PER_SEC;
#else
	#ifdef ICC
	stop = (double)_rdtsc();
	secs = ((double)(stop - start)) / (double) getCPUFreq();
	#else
	gettimeofday(&after, NULL);
	secs = (after.tv_sec - before.tv_sec) + (after.tv_usec - before.tv_usec)/1000000.0;
	#endif
#endif

	flops = TRIP_COUNT * FLOP_PER_ITERATION;
	mflops = flops / 1000000.0f / secs;
	printf("Execution time = %2.3lf seconds\n",secs);	fflush(stdout);
	//printf("MFLOPS: %2.3f mflops\n", mflops);

// print simple test case of data to be sure multiplication is correct
  if (NUM < 5) {
    print_arr("a", a); fflush(stdout);
    print_arr("b", b); fflush(stdout);
    print_arr("c", c); fflush(stdout);
  }

	//free memory
#ifdef ALIGNED
#ifdef WIN32
#ifdef ICC
	_mm_free(buf1);
	_mm_free(buf2);
	_mm_free(buf3);
	_mm_free(buf4);
#else
	_aligned_free(buf1);
	_aligned_free(buf2);
	_aligned_free(buf3);
	_aligned_free(buf4);
#endif //ICC
#else // ICC or GCC Linux
	_mm_free(buf1);
	_mm_free(buf2);
	_mm_free(buf3);
	_mm_free(buf4);
#endif //WIN32
#else //ALIGNED
	free (buf1);
	free (buf2);
	free (buf3);
	free (buf4);
#endif //ALIGNED
*/
}
