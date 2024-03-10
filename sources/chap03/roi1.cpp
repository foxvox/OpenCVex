#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat M = Mat::eye(5, 10, CV_64F);
	Mat Row = M.row(1);
	cout << "Row = " << endl << Row << endl << endl;
	return;
}