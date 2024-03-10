#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	double alpha = 1.0;
	int beta = 0;
	Mat image = imread("d:/contrast.jpg");
	Mat oimage;
	cout << "알파값을 입력하시오: [1.0-3.0]: "; cin >> alpha;
	cout << "베타값을 입력하시오: [0-100]: ";    cin >> beta;


	oimage = image * alpha + beta;
	imshow("Original Image", image);
	imshow("New Image", oimage);
	waitKey();
	return 0;
}