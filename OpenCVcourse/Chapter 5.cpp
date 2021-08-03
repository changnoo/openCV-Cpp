#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;

int main()
{
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	float width = 250, height = 350;
	Mat matrix, imgWarp;

	Point2f source[4] = { {529,142}, {771,190}, {405,395},{674,457} };
	Point2f destination[4] = { {0.0f,0.0f}, {width,0.0f}, {0.0f,height},{width,height} };

	matrix = getPerspectiveTransform(source, destination);
	warpPerspective(img, imgWarp, matrix, Point(width, height));
	
	for (int i = 0; i < 4; i++)
	{
		circle(img, source[i], 10, Scalar(0, 255, 0), FILLED);
	}

	imshow("image", img);
	imshow("image warp", imgWarp);

	waitKey(0);

	return 0;	
}