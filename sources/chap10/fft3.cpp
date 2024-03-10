#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void displayDFT(Mat& src) { ... }

void shuffleDFT(Mat& src)
{
	int cX = src.cols / 2;
	int cY = src.rows / 2;

	Mat q1(src, Rect(0, 0, cX, cY));
	Mat q2(src, Rect(cX, 0, cX, cY));
	Mat q3(src, Rect(0, cY, cX, cY));
	Mat q4(src, Rect(cX, cY, cX, cY));

	Mat tmp;
	q1.copyTo(tmp);
	q4.copyTo(q1);
	tmp.copyTo(q4);
	q2.copyTo(tmp);
	q3.copyTo(q2);
	tmp.copyTo(q3);
}

int main()
{
	Mat src = imread("d:/lenna.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat src_float;
	Mat dft_image;

	// 그레이스케일 영상을 실수 영상으로 변환한다.
	src.convertTo(src_float, CV_32FC1, 1.0 / 255.0);
	dft(src_float, dft_image, DFT_COMPLEX_OUTPUT);
	shuffleDFT(dft_image);
	displayDFT(dft_image);
	return 1;
}