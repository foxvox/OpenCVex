#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

Mat src, src_gray, dst; 
int threshold_value = 0; 
int threshold_type = 0; 

void Threshold_Demo(int, void*)
{
    threshold(src_gray, dst, threshold_value, 255, threshold_type); 
    imshow("결과영상", dst); 
}

int main()
{
    src = imread("C:/DevCpp/OpenCVex/tulip.png"); 
    cvtColor(src, src_gray, CV_BGR2GRAY);
    namedWindow("결과영상", CV_WINDOW_AUTOSIZE); 

    createTrackbar("임계값", "결과영상", &threshold_value, 255, Threshold_Demo); 

    Threshold_Demo(0, 0); 

    while (true)
    {
        int c; 
        c = waitKey(20); 
        // 27 means ESC key 
        if ((char)c == 27)
        {
            break; 
        }
    }   

    return 0;
}



