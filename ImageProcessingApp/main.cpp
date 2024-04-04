#include "Size.h"
#include "Point.h"
#include "Rectangle.h"
#include "Image.h"
#include "ImageProcessing.h"
//#include "Convolution.h"
#include "Drawing.h"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main() {
	{
		Image gator{};
		if (gator.load("gator.ascii.pgm"))
			std::cout << "Image loaded\n";
		else
			std::cout << "Couldn't load image\n";
		std::cout << gator.width() << " " << gator.height() << std::endl;

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
	}
	_CrtDumpMemoryLeaks();
	return 0;
}