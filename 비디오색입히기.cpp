#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    // VideoCapture cap(0);  // 웹캠인 경우 
    VideoCapture cap("C:/DevCpp/OpenCVex/girl.mp4"); 
    if (!cap.isOpened())
    {
        cout << "동영상을 읽을 수 없음" << endl; 
    }

    namedWindow("frame", 1); 

    for (;;)
    {
        Mat frame; 
        cap >> frame; 
        frame += Scalar(0, 0, 80); 
        imshow("frame", frame); 
        // waitKey() 아무것도 안 눌리면 -1 반환 
        if (waitKey(50) >= 0)
            break;
    }

    return 0;
}



