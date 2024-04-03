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

GammaCorrection::GammaCorrection(){
	gamma = 1;
}

GammaCorrection::GammaCorrection(double g){
	gamma = g;
}

void GammaCorrection::process(const Image& src, Image& dst){
	if (src.isEmpty())
		dst = Image();
	else {
		dst = src;
		for (int i = 0; i < src.width(); i++) {
			for (int j = 0; j < src.height(); j++) {
				dst.at(i, j) = std::pow(dst.at(i, j), gamma);
				if (dst.at(i, j) > 255) 
					dst.at(i, j) = 255;
			}
		}
	}
}
