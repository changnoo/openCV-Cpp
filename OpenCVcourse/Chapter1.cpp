#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


// to avoid typing std and cv in front of everything
using namespace std;
using namespace cv;


int main()
{
	//string path = "Resources/test_video.mp4";
	

	// webcam
	VideoCapture cap(0);
	Mat img;

	while (1)
	{
		cap.read(img);
		imshow("img", img);
		waitKey(10);

	}


	return 0;

}