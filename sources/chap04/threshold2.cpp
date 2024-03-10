#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>


using namespace cv;


Mat src, src_gray, dst;

int threshold_value = 0;
int threshold_type = 0;

void Threshold_Demo(int, void*)
{
	threshold(src_gray, dst, threshold_value, 255, threshold_type);
	imshow("��� ����", dst);

}

int main()
{
	src = imread("d:/lenna.png");
	cvtColor(src, src_gray, CV_BGR2GRAY);
	namedWindow("��� ����", CV_WINDOW_AUTOSIZE);

	createTrackbar("�Ӱ谪", "��� ����",
		&threshold_value,
		255, Threshold_Demo);


	Threshold_Demo(0, 0);

	while (true)
	{
		int c;
		c = waitKey(20);
		if ((char)c == 27) {	// ESC Ű�� �ԷµǸ� ���� ���� ����
			break;	
		}
	}
	return 0;
}
