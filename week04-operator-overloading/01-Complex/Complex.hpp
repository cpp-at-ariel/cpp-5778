/**
 * Header file for the Complex class.
 * 
 * @author Ofir Pele
 * @since 2017
 */

#pragma once

#include <iostream>
using namespace std;

class Complex {

private:

    double _re;
    double _im;

public:

    //-------------------------------------
    // Ctors & Destructor
    //-------------------------------------
    // Ctor works also as a conversion from double and
    // also as a default ctor.
    Complex (const double& re= 0.0,
             const double& im= 0.0)
        : _re(re), _im(im) {
    }
    //-------------------------------------

	//-------------------------------------
	// getters
	//-------------------------------------
	double re() const {
		return _re;
	}

	double im() const {
		return _im;
	}
	//-------------------------------------
	
    //-------------------------------------
    // operators
    //-------------------------------------

    //----------------------------------------
    // binary operators
    //----------------------------------------
    Complex& operator+=(const Complex& other) {
        _re+= other._re;
        _im+= other._im;
        return *this;
    }

    Complex& operator*=(const Complex& other) {
        double other_old_re= other._re; // in case we multiply with itself
        double old_re= _re;
		_re= _re*other._re - _im*other._im;
		_im= old_re*other._im + _im*other_old_re;
		// version with bug
		//_re= _re*other._re - _im*other._im;
		//_im= _re*other._im + _im*other._re; 
		return *this;
    }
    //----------------------------------------

    //----------------------------------
    // unary operator
    //----------------------------------
    // the const on the return type is to
    // avoid -c1= c10 from working
    const Complex operator-() const {
        return Complex(-_re , -_im);
    }
    //----------------------------------

    bool operator!() const {
        return _re==0 && _im==0;
    }



    //----------------------------------
    // friend global IO operators
    //----------------------------------
    friend ostream& operator<< (ostream& os, const Complex& c);
    friend istream& operator>> (istream& is, Complex& c);
    //-------------------------------------

    //-------------------------------------
    // friend global binary operators
    //-------------------------------------
    friend const Complex operator+ (const Complex& c1, const Complex& c2);
    friend const Complex operator* (const Complex& c1, const Complex& c2);
    friend bool    operator==(const Complex& c1, const Complex& c2);
    friend bool    operator!=(const Complex& c1, const Complex& c2);
    //-------------------------------------

};

//----------------------------------------
// friend global IO operators
//----------------------------------------
inline ostream& operator<< (ostream& os, const Complex& c) {
    return (os << c._re << '+' << c._im << 'i');
}
//----------------------------------------


//----------------------------------------
// friend global binary operators
//----------------------------------------
inline const Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1._re + c2._re, c1._im + c2._im);
}



inline const Complex operator*(const Complex& c1, const Complex& c2) {
    return Complex (c1._re * c2._re - c1._im * c2._im,
                    c1._re * c2._im + c1._im * c2._re);
}

inline bool operator==(const Complex& c1, const Complex& c2) {
    // this implementation can cause problems with
    // double precision (== for doubles)
    return ((c1._re==c2._re)&&(c1._im==c2._im));
}

inline bool operator!=(const Complex& c1, const Complex& c2) {
    return (!(c1==c2));
}
