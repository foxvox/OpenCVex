#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat A;
	A = imread("d:/lenna.jpg", IMREAD_COLOR);

	Rect r(10, 10, 100, 100);
	Mat D = A(r); // 사각형을 사용하여 관심 영역을 지정한다. 
	D = Scalar(0, 0, 0);	// 관심 영역의 모든 화소가 (0, 0, 0)이 된다. 
	imshow("src", A);
	waitKey();
	return 0;
}