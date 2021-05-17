// vector.cpp
// methods for the Vector class

#define _USE_MATH_DEFINES    // define M_PI

#include <cmath>
#include "vector.h"          // includes <iostream>

namespace VECTOR {
	// private methods
	// calculate magnitude from x and y
	void Vector::set_mag() {
		magnitude_ = sqrt(x_ * x_ + y_ * y_);
	}
	
	// calculate angle from x and y
	void Vector::set_ang() {
		if (x_ == 0.0 && y_ == 0.0)
		{
			angle_ = 0.0;
		}
		else
		{
			angle_ = std::atan2(y_, x_);
		}
	}

	// set x from polar coordinate
	void Vector::set_x() {
		x_ = magnitude_ * cos(angle_);
	}

	// set y from polar coordinate
	void Vector::set_y() {
		y_ = magnitude_ * sin(angle_);
	}

	// public methods
	// default constructor
	Vector::Vector() {
		x_ = y_ = magnitude_ = angle_ = 0.0;
		mode_ = RECT;
	}

	// constructor vector from rectangular coordinates if form is r
	// (the default) or else from polar coordinates if form is p
	Vector::Vector(double n1, double n2, Mode form) {
		mode_ = form;
		if (form == RECT)
		{
			x_ = n1;
			y_ = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			magnitude_ = n1;
			angle_ = n2;
			set_x();
			set_y();
		}
		else
		{
			std::cout << "Incorrect 3rd argument to Vector() -- "
				<< "vector set to 0" << std::endl;
			x_ = y_ = magnitude_ = angle_ = 0.0;
			mode_ = RECT;
		}
	}

	// destructor
	Vector::~Vector() {

	}

	// report
	// report x value
	double Vector::xval() const {
		return x_;
	}
	
	// report y value
	double Vector::yval() const {
		return y_;
	}

	// report magnitude
	double Vector::magval() const {
		return magnitude_;
	}

	// report angle
	double Vector::angval() const {
		return angle_;
	}

	// reset and set mode
	// reset vector from rectangular coordinates if form is
	// RECT (the default) or else from pola rcoordinates if
	// form is POL
	void Vector::reset(double n1, double n2, Mode form) {
		mode_ = form;
		if (form == RECT)
		{
			x_ = n1;
			y_ = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			magnitude_ = n1;
			angle_ = n2;
			set_x();
			set_y();
		}
		else
		{
			std::cout << "Incorrect 3rd argument to Vector() -- "
				<< "vector set to 0" << std::endl;
			x_ = y_ = magnitude_ = angle_ = 0.0;
			mode_ = RECT;
		}
	}

	// set to polar mode
	void Vector::polar_mode() {
		mode_ = POL;
	}

	// set to rectangular mode
	void Vector::rect_mode() {
		mode_ = RECT;
	}

	// operator overloading
	// add two Vectors
	Vector Vector::operator+(const Vector& b) const {
		return Vector(x_ + b.x_, y_ + b.y_);
	}

	// subtract Vector b from a
	Vector Vector::operator-(const Vector& b) const {
		return Vector(x_ - b.x_, y_ - b.y_);
	}

	// reverse sign of Vector
	Vector Vector::operator-() const {
		return Vector(-x_, -y_);
	}

	// multiply Vector by n
	Vector Vector::operator*(double n) const {
		return Vector(n * x_, n * y_);
	}

	// friend methods
	// multiply n by Vector a
	Vector operator*(double n, const Vector& a) {
		return a * n;
	}

	// display rectangular coordinates if mode is RECT,
	// else display polar coordinates if mode is POL
	std::ostream& operator<<(std::ostream& os, const Vector& v) {
		if (v.mode_ == Vector::RECT)
		{
			os << "(x, y) = (" << v.x_ << ", " << v.y_ << ")";
		}
		else if (v.mode_ == Vector::POL)
		{
			os << "(m, a) = (" << v.magnitude_ << ", "
				<< v.angle_ * M_PI << ")";
		}
		else
		{
			os << "Vector object mode is invalid";
		}

		return os;
	}
} // end namespace VECTOR
