#pragma once
#include <fstream>
class Point
{
public:
	Point();
	Point(int xy);

	void Set_Point(int xy);
	void Set_Point(int x,int y);
	int getX()const { return this->x; };
	int getY()const { return this->y; };
	bool operator == (const Point & point) const;
	bool operator != (const Point & point) const;
	friend std::ostream & operator << (std::ostream &out, const Point &c);
	void Marked(char symbol) { this->value = symbol; };
private:
	int x;
	int y;
	char value;
};