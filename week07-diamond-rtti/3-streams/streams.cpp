#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

struct Complex {
	double re, im;

	Complex(double re, double im): re(re), im(im) {}
};

ostream& operator<< (ostream& os, const Complex& c) {
	os << c.re << "+" << c.im << "i";
	return os;
}

int main() {	
	ostringstream s;
	s << 1 << " " << Complex{2,3} << endl;
	cout << s.str() << endl;

	ofstream f("abc.txt");
	f << 1 << " " << Complex{2,3} << endl;

	stringstream s2("1 a bcd");
	int i;
	s2 >> i;
	cout << "i = " << i << endl;
	cout << s2.str() << endl;
	s2 << "efg";
	cout << s2.str() << endl;
}
