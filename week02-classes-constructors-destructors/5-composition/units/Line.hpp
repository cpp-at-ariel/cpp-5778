#pragma once

#include <iostream>
#include "Point.hpp"

/**
 * @author Miri Ben-Nissan
 */
class Line
{
	private:
		Point p1, p2;
	public:
		void SetLine(int x1,int y1,int x2,int y2);
		void SetLine(const Point& p1,const Point& p2);
		void Show();
};
