#include <iostream>
#include <string>

/**
 * @author Ofir Pele
 */
struct C {

	
	//----------------------------------------------------------------------
	// non static members
	//----------------------------------------------------------------------
	double _a = 42.1; // default (can be overridden in initialization list)
	const double _CA = 43.1; // same as above, can be different for different objects!

	//----------------------------------------------------------------------
	// static members
	//----------------------------------------------------------------------
	static const int _SCA= 44; // only compiles with integral type, consider using constexpr instead
	static constexpr double _SCEA= 45.1; // must be static

	static double _sa; // we have to define it separately in cpp file
	static const std::string _SCS;
	//----------------------------------------------------------------------
	
	void print() const {
		std::cout << _a    << std::endl;
		std::cout << _CA   << std::endl;
		std::cout << _SCA  << std::endl;
		std::cout << _SCEA << std::endl;
		std::cout << _sa  << std::endl;
		std::cout << _SCS  << std::endl;
	}
	//----------------------------------------------------------------------

	
	//----------------------------------------------------------------------
	// Ctors
	//----------------------------------------------------------------------
	C() = default; // Don't delete the default ctor
	               // For deleting a default given ctor, you write: C(...) = delete;
	C(bool f1) : _a(420.1), _CA(430.1) {}
	C(int i) : C(false) { // a delegating ctor
		_a *= 10;
	}
	//----------------------------------------------------------------------
	

	
	//----------------------------------------------------------------------
	// enabling conversion to int, we will learn about it later
	//----------------------------------------------------------------------
	operator int() const {
		return _a;
	}
	//----------------------------------------------------------------------
	
};


//----------------------------------------------------------------------
// global functions
//----------------------------------------------------------------------
C    g_foo();
void g_foo2(C c);
int  g_foo3();
//----------------------------------------------------------------------
