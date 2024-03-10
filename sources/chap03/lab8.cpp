#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat img = imread("d:/image1.jpg");
	imshow("img", img);
	Mat roi(img, Rect(10, 10, 2, 2)); // 크기가 2×2 인 사각형을 사용하여 
					   // 관심 영역을 지정한다. 

	cout << "행의 수 = " << roi.rows << endl;
	cout << "열의 수 = " << roi.cols << endl;
	cout << "roi = " << endl << roi << endl << endl;
	waitKey(0);
	return 0;
}