#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("d:/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Input Image", src);
	int histogram[256] = { 0 };

	for (int y = 0; y <src.rows; y++)
		for (int x = 0; x < src.cols; x++)
			histogram[(int)src.at<uchar>(y, x)]++;

	for (int count : histogram)
		cout << count << ",";
	waitKey(0);
	return 0;
}