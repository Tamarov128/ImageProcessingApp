#pragma once
#include "Image.h"
#include "Point.h"

class Drawing {
public:
	static void drawCircle(Image& img, Point center, int radius, unsigned int color);
	static void drawLine(Image& img, Point p1, Point p2, unsigned int color);
	static void drawRectangle(Image& img, Rectangle r, unsigned int color);
	static void drawRectangle(Image& img, Point tl, Point br, unsigned int color);
};