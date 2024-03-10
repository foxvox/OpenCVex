#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src;
	src = imread("d:/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("������", src);
	Mat dst;

	// 8UC1���� 32FC1���� ��ȯ�غ���.
	src.convertTo(dst, CV_32F);

	// 32FC1���� 8UC1�� ��ȯ�غ���.
	dst.convertTo(src, CV_8UC1);
	imshow("����� ����", src);

	waitKey(0);
	return 0;
}