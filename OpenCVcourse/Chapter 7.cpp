#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void getContour(Mat imgDil, Mat img)
{
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	int area;
	float perimeter;
	string objectType;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	// noise filtration
	for (int i = 0; i < contours.size(); i++)
	{
		area = contourArea(contours[i]);
		cout << area << endl;

		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());
		if (area > 1000)
		{
			// find the perimeter
			perimeter = arcLength(contours[i], true);
			
			// find approximated polygon 
			approxPolyDP(contours[i], conPoly[i], 0.02*perimeter, true);

			// conPoly is an array that contains the approximate number of sides of a polygon
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			cout << conPoly[i].size() << endl;
			
			boundRect[i] = boundingRect(conPoly[i]);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(25, 30, 111), 5);
			
			int objCor = (int)conPoly[i].size();
			
			if (objCor == 3)
			{
				objectType = "Tri";
			}
			else if (objCor == 4)
			{
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				if (aspRatio > 0.9 && aspRatio < 1.1)
				{
					objectType = "Square";
				}
				else
					objectType = "Rect";
			}
			else objectType = "Circle";

			putText(img, objectType, { boundRect[i].x, boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 0.74, Scalar(0,0,0), 1);


		
		}
	}
}

int main()
{
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil;

	// Preprocessing of image
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	
	getContour(imgDil, img);

	imshow("Image", img);
	waitKey(0);

	return 0;
}