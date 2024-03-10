#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void shuffleDFT(Mat& src) { ... }
void displayDFT(Mat& src) { ... }

// 원형 필터를 만든다. 
Mat getFilter(Size size)
{
	Mat filter = Mat::ones(size, CV_32FC2);
	circle(filter, size / 2, 10, Vec2f(0, 0), -1);
	return filter;
}
int main()
{
	Mat src = imread("d:/lenna.jpg", IMREAD_GRAYSCALE);
	Mat src_float;
	imshow("original", src);

	// 그레이스케일 영상을 실수 영상으로 변환한다.
	src.convertTo(src_float, CV_32FC1, 1.0 / 255.0);
	Mat dft_image;
	dft(src_float, dft_image, DFT_COMPLEX_OUTPUT);
	shuffleDFT(dft_image);

	Mat highpass = getFilter(dft_image.size());
	Mat result;

	// 원형 필터와 DFT 영상을 서로 곱한다.
	multiply(dft_image, highpass, result);
	displayDFT(result);

	Mat inverted_image;
	shuffleDFT(result);
	idft(result, inverted_image, DFT_SCALE | DFT_REAL_OUTPUT);
	imshow("inverted", inverted_image);
	waitKey(0);
	return 1;
}
