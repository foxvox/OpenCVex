#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat src; 
    src = imread("C:/DevCpp/OpenCVex/light.jpg"); 
    imshow("원영상", src); 

    Mat dst; 
    dst = 255 - src; 
    imshow("변경된 영상", dst); 

    waitKey(0); 
    return 0;
}



