#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "Class.h"

using namespace cv;

int main(int argc, char** argv )
{
    // Test out the usage of the Class class:
    Class obj; // Instantiate an object of type Class

    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat image;
    image = imread( argv[1], 1 );

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);

    waitKey(0);

    return 0;
}
