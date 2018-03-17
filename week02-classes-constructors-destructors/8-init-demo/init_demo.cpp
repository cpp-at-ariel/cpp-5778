/**
 * Demonstration of various ways to initialize objects in C++.
 * 
 * @author Ofir Pele
 * @since 2017
 */


#include "C.hpp"

#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
	{
		cout << "Primitives - aggregate initialization:" << endl;
		double a{1.1};
		int b1 = 1.1;  // compiles in some compilers (bad)
		//int b2 {1.1};  // won't compile (good)
		double c[]{1.1, 2.2};
		double* d = new double[2]{10.1, 20.2};
		int e{}; // initialized to 0

		cout << a << endl;
		cout << b1 << endl;
		cout << c[0] << " " << c[1] << endl;
		cout << d[0] << " " << d[1] << endl;
		cout << e << endl;

		delete[] d;
	}


	{
		cout << endl << "Parameterless ctor:" << endl;
		C c{};
		c.print();
	}


	{
		cout << endl << "bool ctor:" << endl;
		C c{true};
		c.print();
	}


	{
		cout << endl << "int ctor:" << endl;
		C c{3};
		c.print();
	}

	{
		cout << endl << "Function that returns an object:" << endl;
		C c{g_foo()}; // auto c= g_foo(); will also work
		c.print();
	}


	{
		cout << endl << "Function that gets an object:" << endl;
		g_foo2({});  // IMHO hard to read
		g_foo2(C{}); // same as above
		g_foo2(C()); // same as above
	}


	{
		cout << endl << "Most vexing parse problem" << endl;
		double abcd();
		cout << "abcd="  << typeid(abcd).name() << "=" << abcd << endl;  // this is a function 

		double efgh(5);
		cout << "efgh="  << typeid(efgh).name()  << "=" << efgh << endl;  // this is a double

		double ijkl{};
		cout << "ijkl="  << typeid(ijkl).name()  << "=" << ijkl << endl;  // this is a double

		double mnop{5};
		cout << "mnop="  << typeid(mnop).name()  << "=" << mnop << endl;  // this is a double

		int a(C()); // declaring a function [clang generates a warning]
		int b{C{}}; // A C{} is constructed, then converted to int, then value is copied into b
		static_assert(!is_same<int,decltype(a)>::value, "compiler error");
		static_assert(is_same<int,decltype(b)>::value, "compiler error");
	}

	return 0;
}
