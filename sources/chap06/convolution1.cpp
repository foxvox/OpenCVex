#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("D:/lenna.jpg", IMREAD_GRAYSCALE);


	Mat dst(src.size(), CV_8U, Scalar(0));
	if (src.empty()) { return -1; }

	// (1, 1)부터 (rows-1, cols-1) 까지의 화소만 처리
	for (int y = 1; y < src.rows - 1; y++) {
		for (int x = 1; x < src.cols - 1; x++) {
			int sum = 0;
			sum += src.at<uchar>(y - 1, x - 1);
			sum += src.at<uchar>(y, x - 1);
			sum += src.at<uchar>(y + 1, x - 1);
			sum += src.at<uchar>(y - 1, x);
			sum += src.at<uchar>(y, x);
			sum += src.at<uchar>(y + 1, x);
			sum += src.at<uchar>(y - 1, x + 1);
			sum += src.at<uchar>(y, x + 1);
			sum += src.at<uchar>(y + 1, x + 1);
			dst.at<uchar>(y, x) = sum / 9;
		}
	}

	imshow("initial", src);
	imshow("final", dst);
	waitKey(0);
	return 0;
}