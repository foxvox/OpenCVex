#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat image;
	image = imread("d:/rcube.jpg", CV_LOAD_IMAGE_COLOR);

	Mat bgr[3];
	split(image, bgr);

	imshow("src", image); 
	imshow("blue",bgr[0]); 
	imshow("green",bgr[1]); 
	imshow("red",bgr[2]); 
	waitKey(0);
	return 0;
}