# Resize and crop images

## Resize
```C++
  string path = "Resources/test.png";
  Mat img = imread(path);
  Mat imgResize;
  
  cout << img.size() << endl;
  resize(img,imgResize, Size(), scaleX, scaleY);
  cout << imgResize.size() << endl;
  
  imshow("original img", img);
  imshow("resized img", imgResize);
  
  waitKey(0);
```
First, we declare our imgResize matrix variable, then see the original image's size in pixels in x and y direction. 
Using the resize function, we are able to modify either how many pixels the image will have, or we can also scale it down by a certain amount. It is definitely convenient to scale, unless you know a specific number you want to use.


## Crop
```C++
   string path = "Resources/test.png";
   Mat img = imread(path);
   Mat imgResize, imgCrop;
   
   resize(img, imgResize, Size(), scaleX, scaleY);
   
   Rect roi(150,150,150,150);
   
   imgCrop = img(roi);
   
   imshow("Image", img);
   imshow("Image resize", imgResize);
   
   waitKey(0);
```
Here, we use Rect class to define a rectangle and we feed that into our imgCrop, cropping our image.
