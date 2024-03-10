#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("d:/chroma.jpg", IMREAD_COLOR);
	Mat img2 = imread("d:/beach.png", IMREAD_COLOR);

	Mat converted;
	cvtColor(img, converted, COLOR_BGR2HSV);
	Mat greenScreen = converted.clone();
	inRange(converted, Scalar(60-10, 100, 100), Scalar(60+10, 255, 255), greenScreen);

	Mat dst, dst1, inverted;
	bitwise_not(greenScreen, inverted);
	bitwise_and(img, img, dst, inverted);
	bitwise_or(dst, img2, dst1, greenScreen);
	bitwise_or(dst, dst1, dst1);

	imshow("img", img);
	imshow("green", greenScreen);
	imshow("dst", dst);
	imshow("dst1", dst1);
	waitKey(0);
	return 0;
}