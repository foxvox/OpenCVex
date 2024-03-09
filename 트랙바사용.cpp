﻿#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

Mat img;
int red, green, blue; 
int drawing = false;

void on_trackbar(int, void*) {}

void drawCircle(int event, int x, int y, int, void* param)
{
    if (event == EVENT_LBUTTONDOWN)
        drawing = true;
    else if (event == EVENT_MOUSEMOVE)
    {
        if (drawing == true)
            circle(img, Point(x, y), 3, Scalar(0, 0, 255), 10);
    }
    else if (event == EVENT_LBUTTONUP)
        drawing = false;

    imshow("img", img);
}

int main()
{

    img = imread("C:/DevCpp/OpenCvex/light.jpg", IMREAD_COLOR);
    if (img.empty())
    {
        cout << "영상을 읽을 수 없음" << endl; 
    }

    namedWindow("img", 1); 
    imshow("img", img); 

    imshow("img", img);
    setMouseCallback("img", drawCircle);
    createTrackbar("R", "img", &red, 255, on_trackbar);
    createTrackbar("G", "img", &green, 255, on_trackbar);
    createTrackbar("B", "img", &blue, 255, on_trackbar);

    waitKey(0);
    return 0;
}



