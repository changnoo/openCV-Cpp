#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;



int main()
{

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray;
	Mat imgGauss;
	Mat imgCanny;
	Mat imgDilate;
	Mat imgErode;

	// cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgGauss, Size(7,7),5,0);
	Canny(imgGauss, imgCanny, 10, 150);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDilate, kernel);


	imshow("Original img", img);
	imshow("xd", imgCanny);
	imshow("Dilate", imgDilate);
	waitKey(0);


	return 0;
}