#include "Stk.hpp"

#include <string>
#include <iostream>
using namespace std;

int main() {

	string str1("Hello ");
	string str2("world !\n");

	Stk<string>  strStk;
	strStk.push(str2);
	strStk.push(str1);

	while(!strStk.isEmpty()) {
		cout << strStk.top();
		strStk.pop();
	}
	
	strStk.push(str2);
	strStk.push(str1);
	// Old C++ style
	for (Stk<string>::iterator it= strStk.begin(); it!=strStk.end(); ++it) {
		cout << *it;
	}
	// C++-11 style
	for (const auto& val : strStk) {
		cout << val;
	}

	int arr[]= {43, 21, -22};
	// Calling templated ctor, old C++ style
	Stk<int> intStk(arr, arr+sizeof(arr)/sizeof(*arr));
	// Calling templated ctor, C++-11 style
	Stk<int> intStk2(begin(arr), end(arr));
	for (const auto& val : intStk) {
		cout << val << " ";
	}
	cout << endl;
	for (const auto& val : intStk2) {
		cout << val << " ";
	}
	cout << endl;
	
	// Remark: C++-11 allows also to write classes that have {} constructors:
	// Stk<int> intStk3{43, 21, -22};

	cout << intStk2.top() << endl;
	intStk2.top()= 100000;
	cout << intStk2.top() << endl;
	
	return 0;
}
