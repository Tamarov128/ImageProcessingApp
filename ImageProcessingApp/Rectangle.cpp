#include "Rectangle.h"
#include "Point.h"
#include <algorithm>

Rectangle Rectangle::operator+(const Point& point) const
{
    int x = this->x + point.getX();
    int y = this->y + point.getY();
    return Rectangle(x, y, this->width, this->height);
}

Rectangle Rectangle::operator-(const Point& point) const
{
    int x = this->x - point.getX();
    int y = this->y - point.getY();
    return Rectangle(x, y, this->width, this->height);
}

/*
Rectangle Rectangle::operator&(const Rectangle& other) const
{
    //TODO - implementation

    Point thisUL{ x, y };
    Point thisUR{ x + width, y };
    Point thisDL{ x, y + height };
    Point thisDD{ x + width, y + height };

    Point otherUL{ other.x, other.y };
    Point otherUR{ other.x + other.width, other.y };
    Point otherDL{ other.x, other.y + other.height };
    Point otherDR{ other.x + other.width, other.y + other.height };
}

Rectangle Rectangle::operator|(const Rectangle& other) const
{
    //TODO - implementation

    Point thisUL{ x, y };
    Point thisUR{ x + width, y };
    Point thisDL{ x, y + height };
    Point thisDD{ x + width, y + height };

    Point otherUL{ other.x, other.y };
    Point otherUR{ other.x + other.width, other.y };
    Point otherDL{ other.x, other.y + other.height };
    Point otherDR{ other.x + other.width, other.y + other.height };
}
*/