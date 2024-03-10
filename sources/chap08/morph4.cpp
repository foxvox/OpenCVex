#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src, dst, open, close;
	src = imread("d:/test1.png", IMREAD_GRAYSCALE);

	Mat saltpepper_noise = Mat::zeros(src.rows, src.cols, CV_8U);
	randu(saltpepper_noise, 0, 255);

	Mat black = saltpepper_noise < 30;
	Mat white = saltpepper_noise > 225;

	Mat saltpepper_img = src.clone();
	saltpepper_img.setTo(255, white);
	saltpepper_img.setTo(0, black);

	imshow("src", saltpepper_img);

	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));

	morphologyEx(saltpepper_img, open, MORPH_OPEN, element);
	imshow("Opening Demo", open);

	morphologyEx(open, close, MORPH_CLOSE, element);
	imshow("Closing Demo", close);
	waitKey(0);
	return 0;
}