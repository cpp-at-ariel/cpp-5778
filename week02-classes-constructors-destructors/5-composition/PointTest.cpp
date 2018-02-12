#include "Point.hpp"
#include <iostream>
using namespace std;


int main() {
    Point p1;
    p1.setX(10);
    p1.setY(20);
    cout << p1.to_string() << endl;

    Point p2;  
        // Calls no-arg constructor IF EXISTS.
        // If there is NO constructor, VALUE IS UNDEFINED.
        // If there is a constructor but no no-arg constructor: COMPILATION ERROR.
    cout << p2.to_string() << endl;

    //Point p3();
    //cout << p3.to_string() << endl;
    //   Compilation error! Empty parentheses interpreted as a function declaration!

    Point p4(11,21);
    cout << p4.to_string() << endl;

    return 0;
}
