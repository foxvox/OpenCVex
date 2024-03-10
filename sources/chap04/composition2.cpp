#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	double alpha = 0.5; double beta; double input;
	Mat src1, src2, dst;
	cout << "알파값을 입력하시오[0.0-1.0]: ";
	cin >> input;
	src1 = imread("d:/test1.jpg");
	src2 = imread("d:/test2.jpg");
	if (src1.empty()) { cout << "영상1을 로드할 수 없습니다." << endl; return -1; }
	if (src2.empty()) { cout << "영상2을 로드할 수 없습니다." << endl; return -1; }
	beta = (1.0 - alpha);
	addWeighted(src1, alpha, src2, beta, 0.0, dst);
	imshow("Original Image1", src1);
	imshow("Original Image2", src2);
	imshow("선형 합성", dst);
	waitKey(0);
	return 0;
}