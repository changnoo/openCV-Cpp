#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	circle(img, Point(256, 256), 150, Scalar(255, 100, 100), FILLED);
	rectangle(img, Rect(100, 100, 300, 300), Scalar(0, 255, 0), 3);
	line(img, Point(150, 150), Point(300, 300), Scalar(255, 0, 0), 2);

	putText(img, "xDDDDDDD", Point(137, 262), FONT_ITALIC, 2, Scalar(100, 100, 155), 5);

	imshow("img", img);
	waitKey(0);

	return 0;
}