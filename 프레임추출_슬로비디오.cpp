#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    // VideoCapture cap(0);  // 웹캠인 경우 
    VideoCapture cap("C:/DevCpp/OpenCVex/owl.mp4"); 
    if (!cap.isOpened())
    {
        cout << "동영상을 읽을 수 없음" << endl; 
    }

    namedWindow("frame", 1); 

    for (;;)
    {
        Mat frame; 
        cap >> frame; 
        imshow("frame", frame); 
        if (waitKey(100) >= 0)
            break;
    }

    return 0;
}



