#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	double alpha = 1.0;
	int beta = 0;
	Mat image = imread("d:/contrast.jpg");
	Mat oimage = Mat::zeros(image.size(), image.type());
	cout << "알파값을 입력하시오: [1.0-3.0]: "; cin >> alpha;
	cout << "베타값을 입력하시오: [0-100]: ";    cin >> beta;
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			for (int c = 0; c < 3; c++) {
				oimage.at<Vec3b>(y, x)[c] =
					saturate_cast<uchar>(alpha*(image.at<Vec3b>(y, x)[c]) + beta);
			}
		}
	}
	imshow("Original Image", image);
	imshow("New Image", oimage);
	waitKey();
	return 0;
}