/**
 * @author Ofir Pele
 * @since 2017
 */

#include "C.hpp"
#include <iostream>
using namespace std;

decltype(C::_sa)  C::_sa= 46.1; // or double C::_sa{46.1}; 
decltype(C::_SCS) C::_SCS= "hello";

C g_foo() {
	cout << "in g_foo function (creating C with int ctor)" << endl;
	return {1}; // same as C{1}, we don't need to write return type again
	            // controversial whether this is good or bad
}

void g_foo2(C c) {
	cout << "in g_foo2 function (getting a C by value)" << endl;
}

int g_foo3() {
	cout << "in g_foo3 function" << endl;
	return 1;
}
