#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat image, hsv, dst;
	image = imread("d:/lenna.jpg", CV_LOAD_IMAGE_COLOR);
	cvtColor(image, hsv, CV_BGR2HSV);

	Mat array[3];
	split(hsv, array);
	imshow("src", image);	
	imshow("hue", array[0]);
	imshow("saturation", array[1]);
	imshow("value", array[2]);	

	waitKey(0);
	return 0;
}