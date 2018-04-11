/**
 * Demonstrates assignment and brackets operators.
 * 
 * @author Erel Segal-Halevi
 * @since  2018-04
 */
#include "units/IntList.hpp"

#include <iostream>
using namespace std;

int main() {
    IntList l0(1000);
    l0 = 99;
    cout << "l0[5] = " << l0[5] << endl;
    l0[5] = 11;
    cout << "l0[5] = " << l0[5] << endl;
    return 0;
}
