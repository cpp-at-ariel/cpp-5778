/**
 * Demonstrates what happens when an object is destructed twice.
 * 
 * @author Erel Segal-Halevi
 * @since  2018-03
 */
#include "units/IntList.hpp"

#include <iostream>
using namespace std;

int main() {
    cout << (~0) << endl;
    {
        IntList l1(1000);
        l1.fill(99);
        cout << "l1.get(5) = " << l1.get(5) << endl;
        if (3>2) {
            IntList l2 = l1;
            cout << "l2.get(5) = " << l2.get(5) << endl;
        }
        cout << "l1.get(5) = " << l1.get(5) << endl;
    }
    return 0;
}
