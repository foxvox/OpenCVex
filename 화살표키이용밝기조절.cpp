#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std; 

int main()
{
    Mat src; 
    src = imread("C:/DevCpp/OpenCvex/light_img.jpg", IMREAD_COLOR);
    if (src.empty())
    {
        cout << "영상을 읽을 수 없음" << endl; 
    }

    imshow("src", src); 

    while (1)
    {
        int key = waitKeyEx(); 
        // cout << key << " ";

        if (key == 'q')
            break;
        else if (key == 2424832)
            src -= 50;
        else if (key == 2555904)
            src += 50;

        imshow("src", src); 
    }

    return 0; 
}


