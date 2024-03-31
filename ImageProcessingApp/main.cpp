#include "Size.h"
#include "Point.h"
#include "Rectangle.h"
#include "Image.h"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main() {
	{
		Image img1{};
		if (img1.load("fractal_tree.ascii.pgm"))
			std::cout << "Image loaded successfully!\n";
		else
			std::cout << "Image did not load successfully...\n";
		Image img2{};
		img1.getROI(img2, 0, 0, 10, 10);
		std::cout << img2 << std::endl;
	}	
	_CrtDumpMemoryLeaks();
	return 0;
}