#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("d:/lenna.jpg", IMREAD_COLOR);
	Mat dst = Mat();


	resize(src, dst, Size(), 2.0, 2.0);

	imshow("Image", src);
	imshow("Scaled", dst);
	waitKey(0);
	return 1;
}
