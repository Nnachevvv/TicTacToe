#include "Point.h"
#include <iostream>


Point::Point() :x(0), y(0), value(' ')
{
	
}

Point::Point(int xy)
{
	Set_Point(xy);
}

void Point::Set_Point(int xy)
{
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
