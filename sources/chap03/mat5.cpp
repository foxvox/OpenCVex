#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat R = Mat(3, 6, CV_8UC1);
	randu(R, Scalar::all(0), Scalar::all(255));
	cout << "R = " << endl << R << endl << endl;
	return 0;
}