#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	string path = "Resources/test.png";
	Mat img = imread(path);

	Mat imgResize, imgCrop;
	
	
	resize(img, imgResize, Size(), 0.5,0.5);

	Rect roi(250, 100, 300, 280);

	imgCrop = img(roi);


	imshow("img", img);
	imshow("as", imgCrop);
	waitKey(0);


	return 0;
} 