#pragma once
#include "Rectangle.h"
#include "Size.h"
#include "Point.h"
#include <string>

class Image {
private:
	unsigned int** m_data;
	unsigned int m_width;
	unsigned int m_height;
public:
	Image();
	Image(unsigned int w, unsigned int h);

	Image(const Image& other);
	Image& operator=(const Image& other);
	~Image();

	void release();

	unsigned int width() const;
	unsigned int height() const;
	Size size() const;

	void setWidth(unsigned int w);
	void setHeight(unsigned int h);

	bool isEmpty() const;

	static Image zeros(unsigned int width, unsigned int height);
	static Image ones(unsigned int width, unsigned int height);

	unsigned int& at(unsigned int x, unsigned int y);
	unsigned int& at(Point pt);

	unsigned int* row(int y);

	friend std::ostream& operator<<(std::ostream& os, const Image& dt);
	friend std::istream& operator>>(std::istream& is, Image& dt);

	bool load(std::string imagePath);
	bool save(std::string imagePath) const;

	Image operator+(const Image& i);
	Image operator-(const Image& i);
	Image operator*(double s);

	bool getROI(Image& roiImg, Rectangle roiRect);
	bool getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
};