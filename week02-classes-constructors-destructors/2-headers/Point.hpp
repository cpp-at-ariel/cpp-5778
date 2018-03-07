#pragma once

#include <string>
using namespace std;

class Point {
  private:    // Not required. All is private by default.
    int x;
    int y;
    int z;

  public:
    // methods defined inline:
    int getX() { return x;  }
    int getY() { return y;  }

    // methods defined in the CPP file:
    void setX(int);
    void setY(int);

    string to_string();

    // Constructors:
    Point() { x = 5; y = 7; }
    Point(int, int);
};
