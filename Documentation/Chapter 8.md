# Face Detection

```C++
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/objdetect.hpp>

using namespace cv;
using namespace std;

int main()
{
	string path = "Resources/test.png";
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
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255,0,255));
	}

	imshow("Image", img);
	waitKey(0);
	return 0;

}
```
We used a machine learning trained xml file and a bunch of opencv object detection functions to identify the faces in a given image, then we drew a rectangle around it. 

This was rather easy because the algorithm that takes care of detecting a face was already written.
