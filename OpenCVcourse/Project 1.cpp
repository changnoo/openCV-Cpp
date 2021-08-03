#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
vector<vector<int>> newPoints;

vector<vector<int>> findColour(Mat img);
void drawOnCanvas(vector<vector<int>> newPoints);
Point getContours(Mat imgDil);

/*
Project name: Virtual Painter
Author: Chaewoon Song
Date of publishment: August 2nd 2021

Project Description
*/
int main()
{
	VideoCapture webcam(0);

	while (true)
	{
		webcam.read(img);
		newPoints = findColour(img);
		drawOnCanvas(newPoints);
		imshow("Image", img);
		waitKey(1);

	}

	return 0;
}

vector<vector<int>> findColour(Mat img)
{
	vector<vector<int>> myColours{ {0,62,179,179,255,255} }; // orange

	vector<vector<Scalar>> myColourValues{ {0,128,255} };

	vector<String> myColourNames{ "Orange" };
	Mat imgHSV;
	Mat mask;
	Point myPoint;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	for (int i = 0; i < myColours.size(); i++)
	{
		Scalar lower(myColours[i][0], myColours[i][1], myColours[i][2]);
		Scalar upper(myColours[i][3], myColours[i][4], myColours[i][5]);
		inRange(imgHSV, lower, upper, mask);
		imshow(myColourNames[i], mask);

		Point myPoint = getContours(mask);

		if (myPoint.x != 0 && myPoint.y != 0) {
			newPoints.push_back({ myPoint.x, myPoint.y });
		}
	}
	return newPoints;
}

Point getContours(Mat imgDil)
{
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	int area;
	float perimeter;
	Point myPoint(0, 0);

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	// noise filtration
	for (int i = 0; i < contours.size(); i++)
	{
		area = contourArea(contours[i]);
		cout << area << endl;


		if (area > 1000)
		{
			// find the perimeter
			perimeter = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * perimeter, true);

			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
			myPoint.x = boundRect[i].x + boundRect[i].width / 2;
			myPoint.y = boundRect[i].y;

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
		}
	}

	return myPoint;
}

void drawOnCanvas(vector<vector<int>> newPoints)
{
	for (int i = 0; i < newPoints.size(); i++)
	{
		circle(img, (Point(newPoints[i][0],newPoints[i][1])), 10, Scalar(0,128,255), FILLED);
	}
}
