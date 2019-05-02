#pragma once

class Point
{
public:
	Point();
	Point(int xy);

	void Set_Point(int xy);
	void Set_Point(int x,int y);
	int getX()const { return this->x; };
	int getY()const { return this->y; };
private:
	int x;
	int y;
	char value;
};

