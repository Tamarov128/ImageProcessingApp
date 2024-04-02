#pragma once
#include "Image.h"

class ImageProcessing {
public:
	virtual void process(const Image& src, Image& dst) = 0;
};

class BrightnessContrast : public ImageProcessing {
private:
	double alpha;
	int beta;
public:
	BrightnessContrast();
	BrightnessContrast(double a, int b);
	void process(const Image& src, Image& dst) override;
};

