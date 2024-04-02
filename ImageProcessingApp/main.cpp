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
		BrightnessContrast lowBrightness{ 1, -70 };
		lowBrightness.process(gator, gatorLowBrightness);

		if (gatorLowBrightness.save("gator_low_bright.ascii.pgm"))
			std::cout << "Low brightness complete\n";
		else 
			std::cout << "Low brightness not finished...\n";

		Image gatorHighBrightness{};
		BrightnessContrast highBrightness{ 1, 70 };
		highBrightness.process(gator, gatorHighBrightness);

		if (gatorHighBrightness.save("gator_high_bright.ascii.pgm"))
			std::cout << "High brightness complete\n";
		else
			std::cout << "High brightness not finished...\n";

		Image gatorLowContrast{};
		BrightnessContrast lowContrast{ 0.5, 0 };
		lowContrast.process(gator, gatorLowContrast);

		if (gatorLowContrast.save("gator_low_contr.ascii.pgm"))
			std::cout << "Low contrast complete\n";
		else
			std::cout << "Low contrast not finished...\n";

		Image gatorHighContrast{};
		BrightnessContrast highContrast{ 2, 0 };
		highContrast.process(gator, gatorHighContrast);

		if (gatorHighContrast.save("gator_high_contr.ascii.pgm"))
			std::cout << "High contrast complete\n";
		else
			std::cout << "High contrast not finished...\n";
	}	
	_CrtDumpMemoryLeaks();
	return 0;
}