#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{
	Mat img1 = imread("d:/Lenna.jpg", IMREAD_COLOR);
	Mat img2 = imread("d:/card.jpg", IMREAD_COLOR);
	imshow("Original Image", img1);


	img1.push_back(img2);

	imshow("New Image", img1);
	waitKey(0);

	return 0;
}