// OpenCVex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv; 
using namespace std; 

int main()
{
    cv::Mat image = cv::imread("C:/DevCpp/OpenCVex/water_img.jpg", cv::IMREAD_GRAYSCALE);
    if (image.empty())
    {
        cout << "영상을 읽을 수 없음" << endl; 
    }

    imshow("출력 영상", image); 
    waitKey(0); 
 

    return 0; 
}


