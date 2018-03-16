#include "units/Line.hpp"
#include <iostream>
using namespace std;


int main() {
    Point p (3,4);
    cout << p.to_string() << endl;

    Line l1;
    cout << l1.to_string() << endl;
    l1.set(1,2,3,4);
    cout << l1.to_string() << endl;
    return 0;
}
