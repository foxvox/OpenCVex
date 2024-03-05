#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std; 

int main()
{
    Mat img; 
    img = imread("C:/DevCpp/OpenCvex/light2_img.jpg", IMREAD_COLOR);
    if (img.empty())
    {
        cout << "영상을 읽을 수 없음" << endl; 
    }

    imshow("img", img); 

    int x = 300; 
    int y = 300; 

    while (1)
    {
        int key = waitKey(0); 
        if (key == 'q')
            break;
        else if (key == 'a')
            x -= 10;
        else if (key == 'w')
            y -= 10;
        else if (key == 'd')
            x += 10;
        else if (key == 's')
            y += 10; 

        circle(img, Point(x, y), 100, Scalar(0, 255, 0), 5); 
        imshow("img", img); 
    }

    return 0; 
}


