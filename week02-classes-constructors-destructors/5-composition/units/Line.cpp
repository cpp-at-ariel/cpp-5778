#include "Line.hpp"

void Line::SetLine(int x1,int y1,int x2,int y2) {
	p1.setX(x1);
	p1.setY(y1);
	p2.setX(x2);
	p2.setY(y2);
}

void Line::SetLine (const Point& p1,const Point& p2) {
	this->p1 = p1;
	this->p2 = p2;
}
