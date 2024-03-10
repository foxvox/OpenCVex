include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat image = imread("d:/lenna.jpg", IMREAD_GRAYSCALE);

	float weights[] = {
		1 / 9.0F, 1 / 9.0F, 1 / 9.0F,
		1 / 9.0F, 1 / 9.0F, 1 / 9.0F,
		1 / 9.0F, 1 / 9.0F, 1 / 9.0F
	};



	Mat mask(3, 3, CV_32F, weights);
	Mat blur;
	filter2D(image, blur, -1, mask);
	blur.convertTo(blur, CV_8U);

	imshow("image", image);
	imshow("blur", blur);
	waitKey(0);
	return 0;
}