/**
 * Demo of the quotes operator / suffix operator.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
using namespace std;

class Complex {
	double _re, _im;
public:
	Complex(double re, double im=0): _re(re), _im(im) {}
    friend ostream& operator<< (ostream& os, const Complex& c);
    friend const Complex operator+ (const Complex& c1, const Complex& c2);
};


ostream& operator<< (ostream& os, const Complex& c) {
    return (os << c._re << '+' << c._im << 'i');
}

const Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1._re + c2._re, c1._im + c2._im);
}

/**
 * This is the suffix operator.
 */
Complex operator"" _i(long double x) {
	return Complex(0,(double)x);
}

int main() {
	Complex c {3,5}, d {4,6};
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "c+d = " << c+d << endl;

	cout << "4+5i = " << (4.0+5.0_i) << endl;

	Complex e = c + (6.0+7.0_i);
	cout << "e = " << e << endl;
}


