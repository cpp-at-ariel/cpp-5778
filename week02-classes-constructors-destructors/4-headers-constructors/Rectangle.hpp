#include "Point.hpp"

class Rectangle {
	Point topleft, bottomright;

public:
    string to_string() { 
		return "Rectangle[" + topleft.to_string() + " , " + bottomright.to_string() + "]"; 
	}
};
