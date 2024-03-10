#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("d:/lenna.jpg", IMREAD_GRAYSCALE);
	Mat src_float;
	Mat dft_image;

	// �� �׷��̽����� ������ �Ǽ� �������� ��ȯ�Ѵ�.
	src.convertTo(src_float, CV_32FC1, 1.0 / 255.0);

	// �� DFT�� �����Ѵ�. 
	dft(src_float, dft_image, DFT_COMPLEX_OUTPUT);
	return 1;
}