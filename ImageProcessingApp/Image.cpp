#include "Image.h"
#include "Size.h"
#include <string>
#include <iostream>
#include <fstream>
#include <exception>

Image::Image()
{
	m_width = 0;
	m_height = 0;
	m_data = nullptr;
}

Image::Image(unsigned int w, unsigned int h)
{
	m_width = w;
	m_height = h;
	m_data = new unsigned int*[m_width];
	for (int i = 0; i < m_width; i++) {
		m_data[i] = new unsigned int[m_height];
		for (int j = 0; j < m_height; j++)
			m_data[i][j] = 0;
	}
}

Image::Image(const Image& other)
{
	m_width = other.m_width;
	m_height = other.m_height;

	if (other.m_data != nullptr) {
		m_data = new unsigned int* [m_width];
		for (int i = 0; i < m_width; i++) {
			m_data[i] = new unsigned int[m_height];
			for (int j = 0; j < m_height; j++)
				m_data[i][j] = other.m_data[i][j];
		}
	}
	else
		m_data = nullptr;
}

Image& Image::operator=(const Image& other)
{
	if (this != &other) {
		if (m_data != nullptr)
			release();

		m_width = other.m_width;
		m_height = other.m_height;

		if (other.m_data != nullptr) 
		{
			m_data = new unsigned int* [m_width];
			for (int i = 0; i < m_width; i++) {
				m_data[i] = new unsigned int[m_height];
				for (int j = 0; j < m_height; j++)
					m_data[i][j] = other.m_data[i][j];
			}
		}
		else
			m_data = nullptr;
	}
	return *this;
}

Image::~Image()
{
	release();
}

void Image::release()
{
	if (m_data != nullptr) {
		for (int i = 0; i < m_width; i++)
			delete[] m_data[i];
		delete[] m_data;
	}
	m_data = nullptr;
	m_width = 0;
	m_height = 0;
}

unsigned int Image::width() const
{
	return m_width;
}

unsigned int Image::height() const
{
	return m_height;
}

Size Image::size() const
{
	return Size(m_width, m_height);
}

void Image::setWidth(unsigned int w)
{
	m_width = w;
}

void Image::setHeight(unsigned int h)
{
	m_height = h;
}

bool Image::isEmpty() const
{
	if (m_data == nullptr && m_width == 0 && m_height == 0)
		return true;
	return false;
}

Image Image::zeros(unsigned int width, unsigned int height)
{
	Image img{ width, height };
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			img.m_data[i][j] = 0;
	return img;
}

Image Image::ones(unsigned int width, unsigned int height)
{
	Image img{ width, height };
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			img.m_data[i][j] = 1;
	return img;
}

unsigned int& Image::at(unsigned int x, unsigned int y)
{
	return m_data[x][y];
}

unsigned int& Image::at(Point pt)
{
	return m_data[pt.getX()][pt.getY()];
}

unsigned int* Image::row(int y)
{
	if (m_data != nullptr)
		return m_data[y];
	return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Image& dt)
{
	os << "P2" << std::endl;
	os << dt.m_width << " " << dt.m_height << std::endl;
	os << "255" << std::endl;
	for (int j = 0; j < dt.m_height; j++) {
		for (int i = 0; i < dt.m_width; i++)
			os << dt.m_data[i][j] << " ";
		os << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Image& dt)
{
	std::string magic;
	is >> magic;
	unsigned int width, height;
	is >> width >> height;
	dt = Image{ width, height };
	int max_pixels;
	is >> max_pixels;
	for (int j = 0; j < dt.m_height; j++) {
		for (int i = 0; i < dt.m_width; i++)
			is >> dt.m_data[i][j];
	}
	return is;
}

bool Image::load(std::string imagePath)
{
	std::ifstream fin(imagePath);
	if (fin.is_open()) {
		fin >> *this;
		fin.close();
		return true;
	}
	return false;
}

bool Image::save(std::string imagePath) const
{
	std::ofstream fout(imagePath);
	if (fout.is_open()) {
		fout << *this;
		return true;
	}
	return false;
}

Image Image::operator+(const Image& i)
{
	if (m_width != i.m_width or m_height != i.m_height)
		throw std::exception("Images must have the same resolution");

	Image img{ m_width, m_height };
	for (int j=0; j<m_width; j++)
		for (int k = 0; k < m_height; k++)
		{
			unsigned int val = m_data[j][k] + i.m_data[j][k];
			if (val > 255) val = 255;
			img.m_data[j][k] = val;
		}
	return img;
}

Image Image::operator-(const Image& i)
{
	if (m_width != i.m_width or m_height != i.m_height)
		throw std::exception("Images must have the same resolution");

	Image img{ m_width, m_height };
	for (int j = 0; j < m_width; j++)
		for (int k = 0; k < m_height; k++)
		{
			if ((int)m_data[j][k] - (int)i.m_data[j][k] < 0)
				img.m_data[j][k] = 0;
			else
				img.m_data[j][k] = m_data[j][k] - i.m_data[j][k];
		}
	return img;
}

Image Image::operator*(double s)
{
	Image img{ m_width, m_height };
	for (int j = 0; j < m_width; j++)
		for (int k = 0; k < m_height; k++)
			img.m_data[j][k] = (int)(m_data[j][k] * s);
	return img;
}

bool Image::getROI(Image& roiImg, Rectangle roiRect)
{	
	if (m_data == nullptr) 
		return false;
	if ((roiRect.getX() + roiRect.getWidth() > m_width) || (roiRect.getY() + roiRect.getHeight() > m_height))
		return false;

	roiImg = Image{ roiRect.getWidth(), roiRect.getHeight()};
	for (int i = 0; i < roiRect.getWidth(); i++)
		for (int j = 0; j < roiRect.getHeight(); j++)
			roiImg.m_data[i][j] = m_data[roiRect.getX() + i][roiRect.getY() + j];
	return true;
}

bool Image::getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	if (m_data == nullptr || (x + width > m_width) || (y + height > m_height))
		return false;

	roiImg = Image{ width, height };
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			roiImg.m_data[i][j] = m_data[x + i][y + j];
	return true;
}
