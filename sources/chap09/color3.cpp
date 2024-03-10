#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("d:/lenna.jpg");
	Mat img_color;
	applyColorMap(img, img_color, COLORMAP_HOT);
	imshow("img_color", img_color);
	waitKey(0);
}
