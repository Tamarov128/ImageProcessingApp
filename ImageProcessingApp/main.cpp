#include "Size.h"
#include "Point.h"
#include "Rectangle.h"
#include "Image.h"
#include "ImageProcessing.h"
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

		Image gatorLowBrightness{};
		BrightnessContrast lowBrightness{ 1, -30 };
		lowBrightness.process(gator, gatorLowBrightness);

		if (gatorLowBrightness.save("gator_low_bright.ascii.pgm"))
			std::cout << "Low brightness complete\n";
		else 
			std::cout << "Low brightness not finished...\n";

	}	
	_CrtDumpMemoryLeaks();
	return 0;
}