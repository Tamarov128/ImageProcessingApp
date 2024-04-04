#pragma once
#include "ImageProcessing.h"
#include "Size.h"

class Convolution : public ImageProcessing {
private:
	double kernel[3][3];
	unsigned int (*scale)(double pixel);
public:
	Convolution(double k[3][3], unsigned int (*s)(double pixel));
	void process(const Image& src, Image& dst) override;
};