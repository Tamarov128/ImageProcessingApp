#include "Convolution.h"
#include <iostream>

Convolution::Convolution(double k[3][3], unsigned int(*s)(double pixel))
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			kernel[i][j] = k[i][j];
	scale = s;
}

void Convolution::process(const Image& src, Image& dst)
{
	dst = Image{ src.width() - 2 , src.height() - 2 };
	Image src_copy = src;
	for (int i = 0; i < src.width() - 2; i++) {
		for (int j = 0; j < src.height() - 2; j++) {
			double sum = 0.0;
			for (int n = 0; n < 3; n++) {
				for (int m = 0; m < 3; m++) {
					sum += src_copy.at(i + n, j + m) * kernel[n][m];
				}
			}
			dst.at(i, j) = scale(sum);
		}
	}
}

