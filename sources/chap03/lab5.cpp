#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

void sub(Mat img)
{
	img = Scalar(0, 0, 0);		// ������ ��� ȭ�Ҹ� 0���� �����. 
}
int main()
{
	Mat A;
	A = imread("d:/drawing.jpg", IMREAD_COLOR);

	imshow("before", A);	// �Լ� ȣ�� ���� ������ ǥ���Ѵ�. 
	sub(A);			// �Լ��� ������ �����Ѵ�. 
	imshow("after", A);	// �Լ� ȣ�� �Ŀ� ������ ǥ���Ѵ�. 

	waitKey();
	return 0;
}