#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat img = imread("d:/image1.jpg");
	imshow("img", img);
	Mat roi(img, Rect(10, 10, 2, 2)); // ũ�Ⱑ 2��2 �� �簢���� ����Ͽ� 
					   // ���� ������ �����Ѵ�. 

	cout << "���� �� = " << roi.rows << endl;
	cout << "���� �� = " << roi.cols << endl;
	cout << "roi = " << endl << roi << endl << endl;
	waitKey(0);
	return 0;
}