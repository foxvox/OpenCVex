#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
	Mat src, src_gray;

	src = imread("d:/plates.jpg", 1);
	imshow("src", src);
	// �׷��̽����Ϸ� ��ȯ�Ѵ�. 
	cvtColor(src, src_gray, CV_BGR2GRAY);

	// ����þ� ���� ����
	GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);

	vector<Vec3f> circles;

	// ���� �����ϴ� ���� ��ȯ
	HoughCircles(src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows / 8, 200, 50, 0, 0);

	// ���� ���� ���� �׸���. 
	for (size_t i = 0; i < circles.size(); i++) {
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(src, center, 3, Scalar(0, 255, 0), -1, 8, 0); // ���� �߽��� �׸���. 
		circle(src, center, radius, Scalar(0, 0, 255), 3, 8, 0); // ���� �׸���.
	}

	imshow("Hough Circle Transform", src);
	waitKey(0);
	return 0;
}