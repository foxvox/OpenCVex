#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat A = imread("d:/image2.jpg");
	Mat B = A;
	imshow("window 1", A);

	flip(B, B, 0);
	cout << "B¸¸ ¹Ý»ç½ÃÅ´" << endl;
	imshow("window 2", A);

	waitKey(0);
	return 0;
}