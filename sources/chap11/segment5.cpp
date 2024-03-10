#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat frame; // ���� ������
	Mat result; // MOG2�� ���Ͽ� �����Ǵ� ��� ����
	Ptr<BackgroundSubtractor> pMOG2; //MOG2 ��� ���� ��ü
	int keyboard;

	pMOG2 = createBackgroundSubtractorMOG2();
	VideoCapture capture("d:/tennis_ball.mp4");
	if (!capture.isOpened()) { exit(EXIT_FAILURE); }

	while ((char)keyboard != 27) {
		if (!capture.read(frame)) {
			exit(EXIT_FAILURE);
		}
		pMOG2->apply(frame, result);
		imshow("Frame", frame);
		imshow("FG Mask MOG 2", result);
		keyboard = waitKey(30);
	}
	capture.release();
	return 0;
}