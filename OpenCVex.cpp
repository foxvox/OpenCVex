// OpenCVex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv; 
using namespace std; 

int main()
{
    cv::Mat src = cv::imread("C:/DevCpp/OpenCVex/light2_img.jpg", cv::IMREAD_COLOR);
    if (src.empty())
    {
        cout << "영상을 읽을 수 없음" << endl; 
    }

    imshow("src", src); 
    Mat gray, edge, output; 
    cvtColor(src, gray, COLOR_BGR2GRAY);

    imshow("gray", gray); 
    imwrite("C:/DevCpp/OpenCVex/gray.jpg", gray); 


    waitKey(0); 
 

    return 0; 
}


