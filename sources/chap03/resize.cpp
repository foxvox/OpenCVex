#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{

	Mat LoadedImage = imread("d:/Lenna.jpg", IMREAD_COLOR);
	imshow("Original Image", LoadedImage);

	resize(LoadedImage, LoadedImage, Size(100, 100));
	imshow("New Image", LoadedImage);
	waitKey(0);
	return 0;
}