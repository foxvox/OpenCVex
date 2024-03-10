#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void displayDFT(Mat& src)
{
	Mat image_array[2] = { Mat::zeros(src.size(), CV_32F), Mat::zeros(src.size(), CV_32F) };
	// �� DFT ��� ������ 2���� �������� �и��Ѵ�. 
	split(src, image_array);

	Mat mag_image;
	// �� Ǫ���� ��ȯ ������� ���밪�� ����Ѵ�. 
	magnitude(image_array[0], image_array[1], mag_image);

	// �� Ǫ���� ��ȯ ������� ����� ũ�� ������ �α� �����Ϸ� ��ȯ�Ѵ�. 
	// 0���� ������ �ʵ��� 1�� �����ش�. 
	mag_image += Scalar::all(1);
	log(mag_image, mag_image);

	// �� 0���� 255�� ������ ����ȭ�Ѵ�. 
	normalize(mag_image, mag_image, 0, 1, CV_MINMAX);
	imshow("DFT", mag_image);
	waitKey(0);
}

int main()
{
	Mat src = imread("d:/lenna.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat src_float;

	// �׷��̽����� ������ �Ǽ� �������� ��ȯ�Ѵ�.
	src.convertTo(src_float, CV_32FC1, 1.0 / 255.0);
	Mat dft_image;
	dft(src_float, dft_image, DFT_COMPLEX_OUTPUT);
	displayDFT(dft_image);
	return 1;
}