#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat src1 = imread("d:/test1.jpg");
	Mat src2 = imread("d:/test2.jpg");
	Mat dst;
	dst = src1 + src2;
	imshow("Original Image1", src1);
	imshow("Original Image2", src2);
	imshow("New Image", dst);
	waitKey(0);
	return 0;
}