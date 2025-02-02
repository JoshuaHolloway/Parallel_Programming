// OpenCV 3.1.0
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>
#include <iostream>
using namespace cv;
using namespace cv::ml;
using std::cout;
//===================
int main(int, char**)
{
	// Data for visual representation
	int width = 512, height = 512;
	Mat image = Mat::zeros(height, width, CV_8UC3);
	// Set up training data
	int labels[4] = { 1, -1, -1, -1 };
	
	// Initialize training data:
	float trainingData[4][2] = 
	{ { 0, 256 },
		{ 256, 0 },
		{ 512, 0 },
		{ 512, 256 } };
	
	// Copy arr into Mat
	Mat trainingDataMat(4, 2, CV_32FC1, trainingData);
	Mat labelsMat(4, 1, CV_32SC1, labels);

	// Train the SVM
	Ptr<SVM> svm = SVM::create();

	svm->setType(SVM::C_SVC);
	svm->setKernel(SVM::LINEAR);
	svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6));
	svm->train(trainingDataMat, ROW_SAMPLE, labelsMat);

	cout << "JOSH 1 \n";

	// Show the decision regions given by the SVM
	Vec3b green(0, 255, 0), blue(255, 0, 0);
	for (int i = 0; i < image.rows; ++i)
		for (int j = 0; j < image.cols; ++j)
		{
			Mat sampleMat = (Mat_<float>(1, 2) << j, i);
			float response = svm->predict(sampleMat);
			if (response == 1)
				image.at<Vec3b>(i, j) = green;
			else if (response == -1)
				image.at<Vec3b>(i, j) = blue;
		}

	cout << "JOSH 2 \n";

	// Show the training data
	int thickness = -1;
	int lineType = 8;
	int x1 = trainingData[0][0];
	int y1 = trainingData[0][1];

	int x2 = trainingData[1][0];
	int y2 = trainingData[1][1];

	int x3 = trainingData[2][0];
	int y3 = trainingData[2][1];

	int x4 = trainingData[3][0];
	int y4 = trainingData[3][1];

	circle(image, Point(x1, y1), 5, Scalar(0, 0, 0), thickness, lineType);
	circle(image, Point(x2, y2), 5, Scalar(255, 255, 255), thickness, lineType);
	circle(image, Point(x3, y3), 5, Scalar(255, 255, 255), thickness, lineType);
	circle(image, Point(x4, y4), 5, Scalar(255, 255, 255), thickness, lineType);
	
	// Show support vectors
	thickness = 2;
	lineType = 8;
	Mat sv = svm->getUncompressedSupportVectors();
	for (int i = 0; i < sv.rows; ++i)
	{
		const float* v = sv.ptr<float>(i);
		circle(image, Point((int)v[0], (int)v[1]), 6, Scalar(128, 128, 128), thickness, lineType);
	}
	cout << "JOSH 3 \n";


	imwrite("result.png", image);        // save the image
	imshow("SVM Simple Example", image); // show it to the user
	waitKey(0);
}
