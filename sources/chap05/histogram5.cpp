#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main()
{
	Mat src, dst;

	src = imread("d:/plane.jpg", IMREAD_GRAYSCALE);
	imshow("Image", src);
	if (!src.data) { return -1; }

	Mat threshold_image;
	threshold(src, threshold_image, 100, 255, THRESH_BINARY);
	imshow("Thresholded", threshold_image);
	waitKey(0);
	return 0;
}