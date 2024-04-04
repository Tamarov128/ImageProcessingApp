#include "Size.h"
#include "Point.h"
#include "Rectangle.h"
#include "Image.h"
#include "ImageProcessing.h"
<<<<<<< HEAD
//#include "Convolution.h"
#include "Drawing.h"
=======
#include "Convolution.h"

>>>>>>> convolution_module
#include <iostream>
#include <array>
#include <cmath>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

unsigned int meanBlurScale(double pixel) {
	pixel = (double)(pixel / 9.0);
	if ((double)(pixel - (int)(pixel)) >= 0.5)
		pixel += 1;
	return (unsigned int)(pixel);
}

unsigned int gaussianBlurScale(double pixel) {
	pixel = (double)(pixel / 16.0);
	if ((double)(pixel - (int)(pixel)) >= 0.5)
		pixel += 1;
	return (unsigned int)(pixel);
}

unsigned int sobelScale(double pixel) {
	pixel = (double)((pixel + 4 * 255) / 8.0 );
	if ((double)(pixel - (int)(pixel)) >= 0.5)
		pixel += 1;
	return (unsigned int)(pixel);
}

int main() {
	{
		Image gator{};
		if (gator.load("gator.ascii.pgm"))
			std::cout << "Image loaded\n";
		else
			std::cout << "Couldn't load image\n";
		std::cout << gator.width() << " " << gator.height() << std::endl;

<<<<<<< HEAD
		Point center{ 100, 100 };
		Drawing::drawCircle(gator, center, 80, 0);

		if (gator.save("gator_circle.ascii.pgm"))
			std::cout << "Circle drawn\n";
		else
			std::cout << "Couldn't draw circle\n";

			/*Image draw_img{Image::zeros(100, 100)};
		std:: cout << draw_img;
		Point center{ 50, 50 };
		Drawing::drawCircle(draw_img, center, 30, 250);
		Point p1{ 10, 40 };
		Point p2{ 70, 90 };
		Drawing::drawLine(draw_img, p1, p2, 100);
		std::cout << draw_img;
		Point p3{ 10, 80 };
		Point p4{ 50, 90 };
		Drawing::drawRectangle(draw_img, p3, p4, 150);
		draw_img.save("draw_img.ascii.pgm");*/
=======
		double meanBlurKernel[3][3] = { { 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0 } };
		Convolution meanBlur{ meanBlurKernel, meanBlurScale };
		Image gatorMeanBlur{};
		meanBlur.process(gator, gatorMeanBlur);
		if (gatorMeanBlur.save("gator_mean_blur.ascii.pgm"))
			std::cout << "Mean blur successful\n";
		else
			std::cout << "Mean blur unsuccessful\n";

		double gaussianBlurKernel[3][3] = { { 1.0, 2.0, 1.0 }, { 2.0, 4.0, 2.0 }, { 1.0, 2.0, 1.0 } };
		Convolution gaussianBlur{ gaussianBlurKernel, gaussianBlurScale };
		Image gatorGaussianBlur{};
		gaussianBlur.process(gator, gatorGaussianBlur);
		if (gatorGaussianBlur.save("gator_gauss_blur.ascii.pgm"))
			std::cout << "Gaussian blur successful\n";
		else
			std::cout << "Gaussian blur unsuccessful\n";

		double horizontalSobelKernel[3][3] = { { 1.0, 2.0, 1.0 }, { 0.0, 0.0, 0.0 }, { -1.0, -2.0, -1.0 } };
		Convolution horizontalSobel{ horizontalSobelKernel, sobelScale };
		Image gatorHorizontalSobel{};
		horizontalSobel.process(gator, gatorHorizontalSobel);
		if (gatorHorizontalSobel.save("gator_horiz_sobel.ascii.pgm"))
			std::cout << "Horizontal sobel successful\n";
		else
			std::cout << "Horizontal sobel unsuccessful\n";

		double verticalSobelKernel[3][3] = { { -1.0, 0.0, 1.0 }, { -2.0, 0.0, 2.0 }, { -1.0, 0.0, 1.0 } };
		Convolution verticalSobel{ verticalSobelKernel, sobelScale };
		Image gatorVerticalSobel{};
		verticalSobel.process(gator, gatorVerticalSobel);
		if (gatorVerticalSobel.save("gator_vertic_sobel.ascii.pgm"))
			std::cout << "Vertical sobel successful\n";
		else
			std::cout << "Vertical sobel unsuccessful\n";
>>>>>>> convolution_module
	}
	_CrtDumpMemoryLeaks();
	return 0;
}