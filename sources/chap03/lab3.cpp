#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat M(600, 800, CV_8UC3, Scalar(0, 255, 0));
	if (M.empty()) { cout << "������ ���� �� ����" << endl;		return -1; }
	imshow("img", M);

	waitKey(0);
	return 0;
}