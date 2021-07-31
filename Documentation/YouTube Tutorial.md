# This document contains what I learned from a YouTube tutorial on openCV using C++
The tutorial can be found here: https://www.youtube.com/watch?v=2FYm3GOonhk&ab_channel=Murtaza%27sWorkshop-RoboticsandAI

## Introduction to images
Images we see on any screren are composed of pixels. A pixel is defined as: a smallest addressable element in a raster image, or the smallest addressable element in an all points addressable display device; so it is the smallest controllable element of a picture represented on the screen.

![concept-of-pixel1](https://user-images.githubusercontent.com/56273897/127751490-c1df60df-b0d0-40ba-8f39-669a63d7800b.png)

- VGA = 640 x 480
- HD = 1280 x 720
- FHD = 1920 x 1080
- 4kHD = 3840 x 2160

More pixels indicate more controllable elements hence better quality image output.

When images are represented using white and black, they are called gray scale image. It is described by 8 bits, giving 254 shades of gray.

For coloured images, we combine three gray scale images, as known as RGB, and they represent the intensity of red, green, and blue in a given image.
