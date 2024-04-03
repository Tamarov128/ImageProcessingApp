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
	}
	_CrtDumpMemoryLeaks();
	return 0;
}