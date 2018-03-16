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

    Point() {x=y=9;}; 
    Point(int z) {this->x=this->y=z;}
    Point(int x, int y) {this->x=x; this->y=y;}
};
