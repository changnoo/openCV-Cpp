 # Drawing Shapes and text
 ```C++
    Mat img(512,512, CV_8UC3, Scalar(255,255,255));
    
    circle(img, Point(256,256), 155, Scalar(0,69,255), FILLED);
    rectangle(img, Rect(100,100,300,300), Scalar(255,255,255));
    line(img, Point(130, 296), Point(382,296), Scalar(255,255,255));
    
    putText(img, "Anything you want", Point(137,262), FONT_ITALIC, scale, Scalar(0,69, 255), thickness);
    
    imshow("image", img);
    waitKey(0);
 ```
 Here I learned to create an image of any size and colour, how to put a circle, rectangle, line and text on that said image with different starting points and ending points, colours, whether it's edged or filled. Moreover, I also learned that their thickness can be changed.
 
 Being able to manipulate images and create geometrical objects will come in handy in projects.
