#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std; 

Mat img; 
int drawing = false; 

void drawCircle(int event, int x, int y, int, void* param)
{
    if (event == CV_EVENT_LBUTTONDOWN)
        drawing = true;
    else if (event == CV_EVENT_MOUSEMOVE)
    {
        if (drawing == true)
            circle(img, Point(x, y), 3, Scalar(0, 0, 255), 10);
    }
    else if (event == CV_EVENT_LBUTTONUP)
        drawing = false; 

    imshow("img", img); 
}

int main()
{
    
    img = imread("C:/DevCpp/OpenCvex/gc4.jpg", IMREAD_COLOR);
    if (img.empty())
    {
        cout << "영상을 읽을 수 없음" << endl; 
    }

    imshow("img", img); 
    setMouseCallback("img", drawCircle); 
    waitKey(0); 
    imwrite("C:/DevCpp/OpenCvex/gc8.jpg"); 

    return 0; 
}


