#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("d:/lenna.jpg", IMREAD_GRAYSCALE);
	Mat dst = Mat::zeros(Size(src.cols, src.rows), src.type());

	for (int y = 0; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			const int newX = x + 20;
			const int newY = y + 60;
			if(newX > 0 && newY > 0 && newX < src.cols && newY < src.rows)
				dst.at<uchar>(newY, newX) = src.at<uchar>(y, x);
		}
	}
	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	return 1;
}