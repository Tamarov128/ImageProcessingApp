#include "Drawing.h"
#include <iostream>

void Drawing::drawCircle(Image& img, Point center, int radius, unsigned int color)
{
    for (int x = 0; x < img.width(); x++)
        for (int y = 0; y < img.height(); y++)
            if ((x - center.getX()) * (x - center.getX()) + (y - center.getY()) * (y - center.getY()) <= radius * radius) {
                img.at(x, y) = color;
                std::cout << "x:" << x << " y:" << y << std::endl;
            }
}

void Drawing::drawLine(Image& img, Point p1, Point p2, unsigned int color)
{

}

void Drawing::drawRectangle(Image& img, Rectangle r, unsigned int color)
{
}

void Drawing::drawRectangle(Image& img, Point tl, Point br, unsigned int color)
{
}
