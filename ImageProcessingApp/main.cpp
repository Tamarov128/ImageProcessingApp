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

		Image gatorLowGamma{};
		GammaCorrection lowGamma{ 0.7 };
		lowGamma.process(gator, gatorLowGamma);
		if (gatorLowGamma.save("gator_low_gamma.ascii.pgm"))
			std::cout << "Low gamma processed\n";
		else
			std::cout << "Low gamma not finished...\n";

		Image gatorHighGamma{};
		GammaCorrection highGamma{ 1.3 };
		highGamma.process(gator, gatorHighGamma);
		if (gatorHighGamma.save("gator_high_gamma.ascii.pgm"))
			std::cout << "High gamma processed\n";
		else
			std::cout << "High gamma not finished...\n";
	}	
	_CrtDumpMemoryLeaks();
	return 0;
}