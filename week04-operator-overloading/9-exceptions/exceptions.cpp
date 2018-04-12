/**
 * Demostrates exceptions and assertions.
 * @author Erel Segal-Halevi
 * @since  2018-03
 */

#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
using std::cout, std::endl, std::string;

// Throw a string:
double sqrt1(double x) {
	if (x<0)
		throw "x must be non-negative";
	return std::sqrt(x);
}


// Throw an object:
class argument_must_be_positive {};

// Throw an object:
double sqrt2(double x) {
	if (x<0)
		throw argument_must_be_positive{};
	double result = -std::sqrt(x);
	// if (result<0)
	// 	throw "result should be >=0";
	assert (result>=0);
	return result;
}


int main() {
	cout << "std::sqrt(4) " << std::sqrt(4) << endl;
	cout << "std::sqrt(-4) " << std::sqrt(-4) << endl;
/*
	try {
		cout << "sqrt1(4) " << sqrt1(4) << endl;
		cout << "sqrt1(-4) " << sqrt1(-4) << endl;
	} 
	catch (const char* message) {
		cout << "   caught exception: " << message << endl;
	}
*/
	// try {
		// cout << "sqrt2(-4) " << sqrt2(-4) << endl;
		cout << "sqrt2(4) " << sqrt2(4) << endl;
	// } 
	// catch (argument_must_be_positive message) {
	// 	cout << "   caught exception of type " << typeid(message).name() << endl;
	// }
}