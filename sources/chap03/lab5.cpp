#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

void sub(Mat img)
{
	img = Scalar(0, 0, 0);		// 영상의 모든 화소를 0으로 만든다. 
}
int main()
{
	Mat A;
	A = imread("d:/drawing.jpg", IMREAD_COLOR);

	imshow("before", A);	// 함수 호출 전에 영상을 표시한다. 
	sub(A);			// 함수에 영상을 전달한다. 
	imshow("after", A);	// 함수 호출 후에 영상을 표시한다. 

	waitKey();
	return 0;
}