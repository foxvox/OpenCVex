#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void shuffleDFT(Mat& src) { ... }
void displayDFT(Mat& src) { ... }

// 원형 필터를 만든다. 
Mat getFilter(Size size)
{
	Mat filter(size, CV_32FC2, Vec2f(0, 0));
	circle(filter, size / 2, 50, Vec2f(1, 1), -1);
	return filter;
}
// 버터워쓰 필터를 만든다. 
Mat getFilter(Size size)
{
	Mat tmp = Mat(size, CV_32F);
	Point center = Point(tmp.rows / 2, tmp.cols / 2);
	double radius;
	double D = 50;
	double n = 2;

	for (int i = 0; i < tmp.rows; i++) {
		for (int j = 0; j < tmp.cols; j++) {
			radius = (double)sqrt(pow((i - center.x), 2.0) + pow((double)(j - center.y), 2.0));
			tmp.at<float>(i, j) = (float)
				(1 / (1 + pow((double)(radius / D), (double)(2 * n))));
		}
	}
	Mat toMerge[] = { tmp, tmp };
	Mat filter;
	merge(toMerge, 2, filter);
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

	Mat lowpass = getFilter(dft_image.size());
	Mat result;

	// 원형 필터와 DFT 영상을 서로 곱한다.
	multiply(dft_image, lowpass, result);
	displayDFT(result);

	Mat inverted_image;
	shuffleDFT(result);
	idft(result, inverted_image, DFT_SCALE | DFT_REAL_OUTPUT);
	imshow("inverted", inverted_image);
	waitKey(0);
	return 1;
}
