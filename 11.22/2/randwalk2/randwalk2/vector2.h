// vector2.h
// Vector class with <<, mode state

#pragma once

#include <iostream>

namespace VECTOR {
	class Vector
	{
	public:
		enum Mode { RECT, POL };       // rect for rectangular, POL for Polar modes

		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		~Vector();

		// report
		double xval() const;        // report x value
		double yval() const;        // report y value
		double magval() const;      // report magnitude
		double angval() const;      // report angle

		void reset(double n1 = 0.0, double n2 = 0.0, Mode form = RECT);
		void polar_mode();          // set mode to POL
		void rect_mode();           // set mode to RECT

		// operator overloading
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		// friends
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);


	private:
		double x_;                  // horizontal value
		double y_;                  // verticle value
		Mode mode_;                 // RECT or POL
		// private methods for setting values
		void set_xy();
	};
} // end namespace VECTOR
