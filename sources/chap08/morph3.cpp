#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main() 
{
	Mat input_image = (Mat_<uchar>(8, 8) <<
		0, 0, 0, 0, 0, 255, 0, 0,
		0, 255, 255, 255, 0, 0, 0, 0,
		0, 255, 255, 255, 0, 0, 255, 255,
		0, 255, 255, 255, 0, 255, 255, 255,
		255, 255, 255, 0, 0, 255, 255, 255,
		0,0, 0, 0, 255, 255, 255, 255,
		0, 0, 0, 0, 255, 255, 255, 0, 
		0, 0, 0, 0, 0, 0, 0, 0 );
	Mat kernel = (Mat_<int>(3, 3) <<
		1, 1, 1,
		1, 1, 1,
		1, 1, 1);
	Mat output_image;

	morphologyEx(input_image, output_image, MORPH_OPEN, kernel);

	const int rate = 50;
	resize(input_image, input_image, Size(), rate, rate, INTER_NEAREST);
	imshow("Original", input_image);
	resize(output_image, output_image, Size(), rate, rate, INTER_NEAREST);
	imshow("Open", output_image);
	waitKey(0);
	return 0;
}