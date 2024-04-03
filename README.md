# Image Processing App

## Introduction
This is a simple C++ image processing app that provides functionalities for loading, processing, and drawing on grayscale images (using the .pgm extension).

## Modules

### 1. Image and Helper Classes
- **Description**: This module contains classes for handling images and providing helper functions for basic image operations.
- **Features**:
  - Image class for loading, saving, and manipulating images.
  - Helper functions for resizing, cropping, and converting image formats.
- **Usage**:
  ```cpp
  #include "Image.h"
  
  Image img{};
  img.load("path/to/image.jpg");  // Load an image
  img.save("path/to/image.jpg");  // Save an image
  
### 2. Image Processing Classes
- **Description**: This module offers classes for various image processing operations such as adjusting brightness, blurring and edge detection.
- **Features**:
  - Operations for colour adjustment.
  - Convolution class for applying filters like Gaussian blur and Sobel edge detector.
- **Usage**:
  ```cpp
  #include "ImageProcessing.h"
  
  //Template for image processing
  Image img{};
  ProcessClass.process(img, newImg);

### 3. Drawing Module
- **Description**: This module enables drawing basic shapes on images. It can be useful for annotations, highlighting areas of interest, or creating
simple graphics.
- **Features**:
  - Functions for drawing shapes like rectangles, circles, and lines.
- **Usage**:
  ```cpp
  #include "Drawing.h"
  
  // Draw a rectangle on the image
  Drawing::drawRectangle(image, point1, point2, color);
