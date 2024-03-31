#pragma once
#include "Point.h"

class Rectangle {
private:
	int x;
	int y;
	unsigned int width;
	unsigned int height;
public:
	Rectangle() : x{ 0 }, y{ 0 }, width{ 0 }, height{ 0 } 
	{}
	Rectangle(int x, int y, unsigned int width, unsigned int height) : 
		x{ x }, y{ y }, width{ width }, height{ height } 
	{}

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setWidth(unsigned int w) { width = w; }
	void setHeight(unsigned int h) { height = h; }

	int getX() const { return x; }
	int getY() const { return y; }
	unsigned int getWidth() const { return width; }
	unsigned int getHeight() const { return height; }

	// used for translating the rectangle
	Rectangle operator+(const Point& point) const;
	Rectangle operator-(const Point& point) const;

	// & operator computes the intersection between two rectangles
	// | operator computes the union of two rectangles
	/*Rectangle operator&(const Rectangle& other) const;
	Rectangle operator|(const Rectangle& other) const;*/

};