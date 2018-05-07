#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
using namespace std;

struct Complex {
	double re, im;

	Complex(double re, double im): re(re), im(im) {}
};

ostream& operator<< (ostream& os, const Complex& c) {
	os << c.re << "+" << c.im << "i";
	return os;
}

string to_string(const Complex& c) {
	ostringstream s;
	s << c;
	return s.str();
}

int main() {	
	ostringstream s;
	Complex c{2,3};
	s << 1 << " " << c;
	assert(s.str().compare("1 2+3i")==0);
	cout << s.str() << endl;

	ofstream f("abc.txt");
	f << 1 << " " << c << endl;

	stringstream s2("12 aa bcd");
	int i; string a; 
	s2 >> i >> a;
	cout << "i = " << i << endl;
	cout << "a = " << a << endl;
	cout << s2.str() << endl;
	s2 << "efg";
	cout << s2.str() << endl;

	stringstream s3("12 a bcd\n34 b def\n56 C DFE");
	char buffer[200];
	s3.getline(buffer, 200, '\n');
	cin.getline(buffer, 200, ',');
	cout << "first line is " << buffer << endl;
//	cout << "line1 = " << line1 << endl;

	return 0;
}
