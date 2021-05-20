// complex0.cpp
// complex methods

#include "complex0.h"

// constructors and destructor
// default constructor
complex::complex() {
	real_ = imaginary_ = 0.0;
}

// constructor complex object from two doubles
complex::complex(double real, double imaginary) {
	real_ = real;
	imaginary_ = imaginary;
}

// destructor
complex::~complex() {

}

// operators overloading
// overloading +
complex complex::operator+(const complex& b) const {
	return complex(real_ + b.real_, imaginary_ + b.imaginary_);
}

// overloading - : complex a - complex b
complex complex::operator-(const complex& b) const {
	return complex(real_ - b.real_, imaginary_ - b.imaginary_);
}

// overloading - : - complex a
complex complex::operator-() const {
	return complex(-real_, -imaginary_);
}

// overloading * : complex a * complex b
complex complex::operator*(const complex& b) const {
	complex product;

	product.real_ = real_ * b.real_ - imaginary_ * b.imaginary_;
	product.imaginary_ = real_ * b.imaginary_ + imaginary_ * b.real_;

	return product;
}

// overloading * : complex a * double n
complex complex::operator*(double n) const {
	return complex(n * real_, n * imaginary_);
}

// overloading ~ : complex conjugate
complex complex::operator~() const {
	return complex(real_, -imaginary_);
}

// friends
// overloading * : double n * complex a
complex operator*(double n, const complex& a) {
	return a * n;
}

// overloading >>
std::istream& operator>>(std::istream& is, complex& a) {
	std::cout << "real: ";
	if (is >> a.real_)
	{
		std::cout << "imaginary: ";
		is >> a.imaginary_;
	}

	return is;
}

// overloading <<
std::ostream& operator<<(std::ostream& os, const complex& a) {
	os << "(" << a.real_ << "," << a.imaginary_ << "i)";

	return os;
}
