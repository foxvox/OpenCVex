#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src;
	src = imread("d:/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("원영상", src);
	Mat dst;

	// 8UC1에서 32FC1으로 변환해본다.
	src.convertTo(dst, CV_32F);

	// 32FC1에서 8UC1로 변환해본다.
	dst.convertTo(src, CV_8UC1);
	imshow("변경된 영상", src);

	waitKey(0);
	return 0;
}