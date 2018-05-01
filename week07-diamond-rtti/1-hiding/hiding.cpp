#include <iostream>
using namespace std;


class Base
{
public:
	void f(bool i) { cout << "f(bool)" << endl; }
};

class Derived: Base {
public:
	void f(int i) { cout << "f(int)" << endl; }
};

int main()
{	
	Base b;
	b.f(3);    // imperfect match to Base::f
	b.f(true); // perfect match to Base::f

	Derived d;
	d.f(3);    // perfect match to Derived::f
	d.f(true); // imperfect match to Base::f and Derived::F
}
