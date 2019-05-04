#include "Point.h"
#include <iostream>


Point::Point() :x(0), y(0), value(' ')
{
	
}

Point::Point(int xy):value(' ')
{
	Set_Point(xy);
}

void Point::Set_Point(int xy)
{
	if (xy<0)
	{
		x = -1;
		y = -1;
	}
	if (xy<10)
	{
		this->x = 0;
	}
	else
	{
		this->x = xy / 10;
	}
	this->y = xy % 10;
}

void Point::Set_Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool Point::operator==(const Point & point) const
{
	return value == point.value;
}

bool Point::operator!=(const Point & point) const
{
	return !(*this == point);
}

std::ostream & operator<<(std::ostream & out, const Point & c)
{
	out << c.value;
	return out;
}
