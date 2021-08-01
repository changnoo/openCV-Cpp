# Colour detection
```C++
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	string path = "Resources/lambo.png";
	Mat img = imread(path);
	Mat imgHSV, mask;

	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	int hmin = 0.0f, smin = 110, vmin = 153;
	int hmax = 19, smax = 240, vmax = 255;

	namedWindow("Trackbars", (640, 380));
	createTrackbar("Hue min", "Trackbars", &hmin, 179);
	createTrackbar("Sat min", "Trackbars", &smin, 255);
	createTrackbar("Value min", "Trackbars", &vmin, 255);
	
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Value Max", "Trackbars", &vmax, 255);

	while (true) {


		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		 
		inRange(imgHSV, lower, upper, mask);



		imshow("image", img);
		imshow("img HSV", imgHSV);
		imshow("mask", mask);
		waitKey(1);
	}
	return 0;

}
```
When we are trying to detect colours, we often convert the image into an HSV file, meaning Hue, Saturation and Value file. It is done by converting the image from original into HSV.

The trackbar function lets us find the right amount of HSV to isolate a colour we are trying to detect. Solid and distinct colours typically are easy to detect because the colours in each object don't vary. However, if an object is of multiple colours, and gradient, it is much more difficult to isolate using this method.
