#include "Drawing.h"
#include <iostream>

void Drawing::drawCircle(Image& img, Point center, int radius, unsigned int color)
{
    for (int x = 0; x < img.width(); x++)
        for (int y = 0; y < img.height(); y++)
            if ((x - center.getX()) * (x - center.getX()) + (y - center.getY()) * (y - center.getY()) <= radius * radius) {
                img.at(x, y) = color;
            }
}

void Drawing::drawLine(Image& img, Point p1, Point p2, unsigned int color)
{
    int x1 = p1.getX(), y1 = p1.getY();
    int x2 = p2.getX(), y2 = p2.getY();
    if (x1 <= x2) {
        if (y1 <= y2)
            for (int x = x1, y = y1; x <= x2, y <= y2; x++, y++)
                img.at(x, y) = color;
        else
            for (int x = x1, y = y2; x <= x2, y <= y1; x++, y++)
                img.at(x, y) = color;
    }
    else {
        if (y1 <= y2)
            for (int x = x2, y = y1; x <= x1, y <= y2; x++, y++)
                img.at(x, y) = color;
        else
            for (int x = x2, y = y2; x <= x1, y <= y1; x++, y++)
                img.at(x, y) = color;
    }
}

void Drawing::drawRectangle(Image& img, Rectangle r, unsigned int color)
{
    for (int x = r.getX(); x < r.getX() + r.getWidth(); x++)
        for (int y = r.getY(); y < r.getY() + r.getHeight(); y++)
            img.at(x, y) = color;
}

void Drawing::drawRectangle(Image& img, Point tl, Point br, unsigned int color)
{
    for (int x = tl.getX(); x < br.getX(); x++)
        for (int y = tl.getY(); y < br.getY(); y++)
            img.at(x, y) = color;
}
