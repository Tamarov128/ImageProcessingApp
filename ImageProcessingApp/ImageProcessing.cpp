#include "ImageProcessing.h"
#include "Image.h"
#include <cmath>

BrightnessContrast::BrightnessContrast() {
	alpha = 1;
	beta = 0;
}

BrightnessContrast::BrightnessContrast(double a, int b){
	alpha = a;
	beta = b;
}

void BrightnessContrast::process(const Image& src, Image& dst)
{
	if (src.isEmpty())
		dst = Image();
	else {
		dst = src;
		dst = dst * alpha;
		Image b = Image::ones(src.width(), src.height()) * abs(beta);
		if (beta < 0)
			dst = dst - b;
		else
			dst = dst + b;
	}
}
