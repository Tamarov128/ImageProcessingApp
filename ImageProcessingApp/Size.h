#pragma once
class Size {
private:
	unsigned int width;
	unsigned int height;
public:
	Size() : width{ 0 }, height{ 0 } {}
	Size(unsigned int w, unsigned int h) : width{ w }, height{ h } {}

	void setWidth(unsigned int w) { width = w; }
	void setHeight(unsigned int h) { height = h; }

	unsigned int getWidth() const { return width; }
	unsigned int getHeight() const { return height; }

	bool operator==(const Size& size) const
	{ 
		return width * height == size.width * size.height; 
	}
	bool operator<(const Size& size) const
	{
		return width * height < size.width * size.height;
	}
	bool operator<=(const Size& size) const
	{
		return width * height <= size.width * size.height;
	}
	bool operator>(const Size& size) const
	{
		return width * height > size.width * size.height;
	}
	bool operator>=(const Size& size) const
	{
		return width * height >= size.width * size.height;
	}
};