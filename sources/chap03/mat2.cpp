#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat M;
	M.create(3, 4, CV_8UC3);
	cout << "M = " << endl << M << endl << endl;
	return 0;
}