#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("d:/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Original Image", img);

	for (int r = 0; r < img.rows; r++)
		for (int c = 0; c < img.cols; ++c)
			img.at<uchar>(r, c) = img.at<uchar>(r, c) + 30;

	imshow("New Image", img);
	waitKey(0);
	return 0;
}