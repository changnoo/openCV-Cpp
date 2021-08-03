#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/objdetect.hpp>
#include <string>

using namespace cv;
using namespace std;

int main()
{
	string path = "Resources/three-women.jpg";
	Mat img = imread(path);

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty() == true)
	{
		cout << "File corrupt" << endl;
	}

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces,1.1, 10);

	for (int i = 0; i < faces.size(); i++)
	{
		string woman = "Woman ";
		int numwom = i + 1;
		
		woman = woman + to_string(numwom);

		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255,0,255));
		putText(img, woman, faces[i].tl(), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 0), 2);

	}

	imshow("Image", img);
	waitKey(0);
	return 0;

}