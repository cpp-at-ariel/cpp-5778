#pragma once

#include <string>
using namespace std;

class Point {
  private:
    int x;
    int y;
  public:
    void setX(int);
    void setY(int);
    string to_string();

    Point() = default;
    Point(int x) {this->x=x; this->y=x;}
    Point(int x, int y) {this->x=x; this->y=y;}
};
