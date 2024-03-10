#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img1, mask;

	img1 = imread("C:/DevCpp/OpenCVex/bird3.png", IMREAD_COLOR);
	if (img1.empty()) { cout << "영상1을 로드할 수 없습니다." << endl; return -1; }
	mask = imread("C:/DevCpp/OpenCVex/mask.png", IMREAD_COLOR);
	if (mask.empty()) { cout << "영상2를 로드할 수 없습니다." << endl; return -1; }

	Mat dst = img1.clone();
	imshow("img1", img1);
	imshow("mask", mask);

	bitwise_and(img1, mask, dst);
	imshow("dst", dst);
	waitKey(0);
	return 0;
}