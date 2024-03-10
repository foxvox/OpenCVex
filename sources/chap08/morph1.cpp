#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat src, dst, erosion_dst, dilation_dst;
	src = imread("d:/test.png", IMREAD_GRAYSCALE);

	threshold(src, dst, 127, 255, THRESH_BINARY);
	imshow("dst", dst);

	Mat element = getStructuringElement(MORPH_RECT,
		Size(3, 3),
		Point(-1, -1));

	erode(dst, erosion_dst, element);
	imshow("Erosion Demo", erosion_dst);
	waitKey(0);
	return 0;
}