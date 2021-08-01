# How to Warp Images

```C++
    string path = "Resources/cards.jpg";
    Mat img = imread(path);
    
    float width = 250, height = 350;
    Mat matrix, imgWarp;
    
    Point2f source[4] = { {529,142}, {771,190}, {405,395}, {674,457} };
    point2f destination[4] = { {0.0f,0.0f}, {width, 0.0f}, {0.0f, height}, {width, height} };
    
    matrix = getPerspectiveTransform(source, destination);
    
    warpPerspective(img, imgWarp, matrix, Point(width,height));
    
    for (int i = 0; i < 4; i++)
    {
        circle(img, source[i], Scalar(0,255,0), FILLED);
    }
    
    imshow("image", img);
    imshow("img warp", img);
    
    waitKey(0);
    return 0;
```

Here, we want to warp the image of the card to make it look like we're seeing it from a bird's eye view perspective. To do this, we first define coordinates for the original card and the desired destination.

We declare a matrix variable called matrix and perform perspective transformation using getPerspectiveTransform function. The matrix varialbe now contains transformed coordinates

Using warpPerspective function, we warp the original image to another matrix, and give it its dimensions.

The for loop is for colouring the edges that we picked for warping to illustrate which points we have taken.

## Result
The result is as shown below
![cards](https://user-images.githubusercontent.com/56273897/127758175-290db5b6-c2af-4e3c-b41d-404d95423186.PNG)

It is cool to think that algorithms like the ones I used have been used to create scanner app and many other application. Technology is truly indistinguishable from magic at a high level.

