#pragma once

#include <iostream>
#include "Point.hpp"

class Line
{
	private:
		Point p1, p2;
	public:
		Line() { }
		Line(int x1,int y1,int x2,int y2): 
			p1(x1,y1), p2(x2,y2) { }
		void set(int x1,int y1,int x2,int y2);
		void set(const Point& p1,const Point& p2);
		string to_string();
};
