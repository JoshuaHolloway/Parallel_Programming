// main.cpp
//-------------------------------------------------------------------
#include "header.h"
using cv::Mat;
//-------------------------------------------------------------------
Mat load_image(const char* image_path) {
	Mat image = cv::imread(image_path, CV_LOAD_IMAGE_COLOR);
	image.convertTo(image, CV_32FC3);
	cv::normalize(image, image, 0, 1, cv::NORM_MINMAX);
	return image;
}
//-------------------------------------------------------------------
int do_main()
{
	//Read in image
	Mat mat = load_image("img.jpg");

	// Call the wrapper function
	return kernel_wrapper(mat);
}
//---------------------------------------------------------------------
int main(int argc, char* argv[])
{
	try
	{
		do_main();
		return 0;
	}
	catch (std::exception const& err)
	{
		std::printf("%s\n", err.what());
		getchar();
		return -1;
	}
}
//---------------------------------------------------------------------
