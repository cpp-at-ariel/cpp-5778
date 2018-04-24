/**
 * Demostrates exceptions and assertions.
 * @author Erel Segal-Halevi
 * @since  2018-03
 */

#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
using namespace std;

// Throw a string:
double sqrt1(double x) {
	if (x<0)
		throw string(
			"x must be non-negative, but it is "
			+to_string(x));
	return std::sqrt(x);
}


int main() {
	cout << "std::sqrt(4) = " << std::sqrt(4) << endl;
	cout << "std::sqrt(-4) = " << std::sqrt(-4) << endl;
	try {
		cout << "sqrt1(4) = " << sqrt1(4) << endl;
		cout << "sqrt1(-4) = " << sqrt1(-4) << endl;
	}
	catch (const string& message) {
		cout << "   caught exception: " << message << endl;
	}

	cout << sqrt1(-9) << endl;
}
