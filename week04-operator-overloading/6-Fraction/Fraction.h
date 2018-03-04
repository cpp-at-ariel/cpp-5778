/**
 * Header of the Fraction class.
 * 
 * @author Ofir Pele
 * @since 2017
 */

#pragma once

#include <iostream>
using namespace std;

class Fraction
{
	friend 	istream& 	operator>> (istream& is, Fraction& f);
	friend 	ostream& 	operator<< (ostream& os, const Fraction& f);
	friend 	Fraction 	operator+  (const Fraction& f1, const Fraction& f2);
	friend	Fraction 	operator-  (const Fraction& f1, const Fraction& f2);
	friend 	Fraction 	operator*  (const Fraction& f1, const Fraction& f2);
	friend 	Fraction 	operator/  (const Fraction& f1, const Fraction& f2);
	//friend  Fraction    sqrt(const Fraction& f);
public:
	double 	ToDouble() const { return double(nom) / den; }
	operator double() const { return ToDouble(); }
	Fraction(int nn, int dn): nom(nn), den(dn) { }
	//Fraction(int nn): nom(nn), den(1) { }

	Fraction&	operator++();   	//prefix - ++a
	Fraction 	operator++(int); 	//postfix - a++
private:
	//operations
	int 	gcd(int i, int j);
	void 	reduce();
	//data
	int 	nom;	//nominator
	int 	den;	//denominator
};
