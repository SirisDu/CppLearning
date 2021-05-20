// complex0.h
// complex class

#pragma once

#include <iostream>

class complex
{
public:
	complex();
	complex(double real, double imaginary);
	~complex();

	complex operator+(const complex& b) const;
	complex operator-(const complex& b) const;
	complex operator-() const;
	complex operator*(const complex& b) const;
	complex operator*(double n) const;
	complex operator~() const;

	friend complex operator*(double n, const complex& a);
	friend std::istream& operator>>(std::istream& is, complex& a);
	friend std::ostream& operator<<(std::ostream& os, const complex& a);

private:
	double real_;           // real part of a complex
	double imaginary_;      // imaginary part of a complex
};
 