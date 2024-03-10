#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("d:/crayfish.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) { return -1; }

	Mat dst;
	equalizeHist(src, dst);

	imshow("Image", src);
	imshow("Equalized", dst);
	waitKey(0);
	return 0;
}