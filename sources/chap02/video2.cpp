#include "opencv2/opencv.hpp"
using namespace cv;

int main()
{
	// VideoCapture cap(0); 
	VideoCapture cap("d:/trailer.mp4");
	if (!cap.isOpened())
		return -1;

	namedWindow("frame", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame;

		frame += Scalar(100, 0, 0);
		imshow("frame", frame);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}