#include "Point.hpp"

// The following line demonstrates the importance of "pragma once":
#include "Rectangle.hpp"  

#include <iostream>
using namespace std;


int main() {
    // Point p1;
    //     // Calls no-arg constructor IF EXISTS.
    //     // If there is NO constructor, VALUE IS UNDEFINED.
    //     // If there is NO no-arg constructor: COMPILATION ERROR.
    // cout << "p1 = " << p1.to_string() << endl;

    // p1.setX(10);
    // p1.setY(20);
    // cout << "p1 = " << p1.to_string() << endl;

    // Point p2 {11,21};
    // cout << "p2 = " << p2.to_string() << endl;

    // cout << "Point{7} = " << Point{7}.to_string() << endl;

    // Point array1[5];
    // cout << "array1[3] = " << array1[3].to_string() << endl;

    Point array2[5] {1, 2, 3, 4, 5};
    cout << "array2[1] = " << array2[1].to_string() << endl;
    cout << "array2[3] = " << array2[3].to_string() << endl;

    // Point array3[5] { {1,2} , {2,3} , {3,4}};
    // cout << "array3[1] = " << array3[1].to_string() << endl;
    // cout << "array3[3] = " << array3[3].to_string() << endl;

    // Point array4[3] { 1 , {2,3} };
    // cout << "array4[0] = " << array4[0].to_string() << endl;
    // cout << "array4[1] = " << array4[1].to_string() << endl;


    // //Point p3();
    // //cout << p3.to_string() << endl;
    // //   Compilation error! Empty parentheses interpreted as a function declaration!
    return 0;
}
