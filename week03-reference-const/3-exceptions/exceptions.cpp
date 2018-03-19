#include <iostream>
#include <cmath>
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
	double result = std::sqrt(x);
	assert (result>=0);
	return result;
}


int main() {
	cout << "std::sqrt(-1) " << std::sqrt(-1) << endl;

	try {
		cout << "sqrt1(-1) " << sqrt1(-1) << endl;
	} 
	catch (char const* message) {
		cout << "   caught exception: " << message << endl;
	}

	try {
		cout << "sqrt2(-1) " << sqrt2(-1) << endl;
	} 
	catch (argument_must_be_positive message) {
		cout << "   caught exception of type " << typeid(message).name() << endl;
	}	
}