#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat A = imread("d:/image2.jpg");
	Mat B = imread("d:/logo.png");
	Mat roi(A, Rect(A.cols - B.cols, A.rows - B.rows, B.cols, B.rows));
	B.copyTo(roi);

	imshow("result", A);
	waitKey(0);
	return 0;
}