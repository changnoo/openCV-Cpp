# OpenCV Basic Functions

1. Converting image to gray-scale 

```C++
  string path = "Resources/test.png";
  Mat img = imshow(path);
  Mat imgGray;
  
  cvtColor(img, imgGray, COLOR_BGR2GRAY);
  
  imshow("Original img", img);
  imshow("Gray img", imgGray);
  waitKey(0);
```
Here we used the function cvtColor to convert colors. We learned that in C++, unlike Python, we need to include the output variable inside the function. For more information, in Python, it is customary to assign the function output to a variable.

2. Gaussian Blur

```C++
  GaussianBlur(img,imgBlur, Size(5,5),3,0);
  imshow("Blurred img", imgBlur);
```

Here we used the GaussianBlur function to blur our image. The intensity of blurring can be modified using the size parameter.

3. Edge detection using Canny, dilate, and erode

```C++
   GaussianBlur(img, imgBlur, Size(3,3), 3, 0);
   Canny(imgBlur, imgCanny, 25, 75);
   
   Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
   dilate(imgCanny, imgDilate, kernel);
   erode(imgDil, imgErode, kernel);
   
   imshow("Canny img", imgCanny);
   imshow("Dilation img", imgDil);
   imshow("Erode img", imgErode);
```

The rule of thumb when performing edge detection is to blur the image we're working on first, then using Canny, find the edges. 
We can "dilate" or intensify the edges in order to thicken the lines and make them look more filling. Usually it takes empirical efforts to find the right amount of dilation.
