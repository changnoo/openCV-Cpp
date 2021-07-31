# Read images, videos, and webcams

Using the openCV library, we include the following 3 header files

<opencv2/imgcodecs.hpp>
<opencv2/highgui.hpp>
<opencv2/imgproc.hpp>

Since we will be using the standard library functions as well as openCV functions, it is convenient to define the namespace for them to avoid having to type std and cv in front of the functions, as follows:
 using namespace cv;
 using namespace std;

Now, we can define a string as such:
- string path = "Resources/test.png"; instead of std::string ...;


A new data type "Mat" is introduced by the openCV library, and it is a data type of "Matrix" that handles all the images. Whenever we are talking about images, we will be using the data type Mat, just like how we would use the data type "int" to represent integer numbers. It's just another type of variable.

## Example code
An example code that reads an image from a local folder and displays to the screen goes as follows:

```c++
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


// to avoid typing std and cv in front of everything
using namespace std;
using namespace cv;


int main()
{
  // for reading images and displaying on the screen
  // ################################################
  string path = "Resources/test.png";
  Mat img = imread(path);
  imshow("Test image", img);
  waitKey(0);
	return 0;
  // ################################################
  
  
  
  // for reading videos and playing on the screen
  // ################################################
  string path = "Resources/test_video.mp4";
  videoCapture cap(path);
  Mat img;
  
  while(true)
  {
    cap.read(img);
    imshow("Video", img);
    waitKey(10);
  }
  
  return 0;
  // ################################################
  
  
  
  // for reading videos from the webcam
  // ################################################
  VideoCapture cap(0);
	Mat img;
  
	while (1)
	{
		cap.read(img);
		imshow("webcam vid", img);
		waitKey(10);

	}
  return 0;
  // #################################################
}
```
## Stuff learned
- Mat: a Matrix data type. we use it for images or videos. Videos are just a bunch of images shifting through
- imread: reads an image
- imshow: shows an image 
- waitKey(): delays something. 0 is for delaying forever
- VideoCapture: class used for capturing videos from webcam

