#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	// load the image
	string path = "Resources/lambo.png";
	Mat img = imread(path);

	// we want to detect colours like orange.
	// to do this we have to preprocess the image and find the right 
	// HSV values that "mask" our wanted colour.

	// mask as in the HSV combination isolates the colour only and removes 
	// other colours from the image
	

	// STAGE 1: preprocessing of image
	Mat imgHSV, mask;
	
	// we first convert our RGB photo into a HSV photo
	// which allows us to remove the white background portion
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	
	// (hue, saturation, value)
	int hue_min = 0, sat_min = 160, val_min = 130;
	int hue_max = 179, sat_max = 255, val_max = 255;

	
	// STAGE 2: Create a trackbar to find the HSV combination for a mask
	namedWindow("Trackbars", (640, 380));
	// hue
	createTrackbar("Hue Min", "Trackbars", &hue_min, 179);
	createTrackbar("Hue Max", "Trackbars", &hue_max, 179);
	// sat
	createTrackbar("Sat Min", "Trackbars", &sat_min, 255);
	createTrackbar("Sat Max", "Trackbars", &sat_max, 255);
	// val
	createTrackbar("Val Min", "Trackbars", &val_min, 255);
	createTrackbar("Val Max", "Trackbars", &val_max, 255);
	
	// STAGE 3: LOOP TO FIND COLOUR
	while (true)
	{
		// these values need to be continuously updated using the 
		// trackbars so they are put in the loop.
		Scalar lower_limit(hue_min, sat_min, val_min);
		Scalar upper_limit(hue_max, sat_max, val_max);

		// using the inRange function, we set a threshold to isolate our colour
		// the function lower and upper threshold such that within this range
		// our wanted colour outputs a value of 255. If our colour is not within
		// this range, the value is set to 0, making it invisible.

		// After we find the right HSV values to mask the colour, we can
		// hard-code it to find the colour immediately.
		inRange(imgHSV, lower_limit, upper_limit, mask);


		imshow("image", img);
		imshow("HSV", imgHSV);
		imshow("Mask", mask);
		waitKey(1);
	}

	return 0;

}