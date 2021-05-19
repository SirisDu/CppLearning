// stonewt2.cpp
// Stonewt methods

#include <iostream>
#include "stonewt2.h"

// constructors and destructor
// default constructor, weight = 0
Stonewt::Stonewt() {
	stone_ = pounds_ = pds_left_ = 0;
	type_ = stn_;
}

// constructor Stonewt object from double value
Stonewt::Stonewt(double pounds) {
	stone_ = int(pounds) / Lbs_per_stn;       // integer division
	pds_left_ = int(pounds) % Lbs_per_stn + pounds - int(pounds);
	pounds_ = pounds;
	type_ = lbs_double_;
}

// construc Stonewt object from stone, double values
Stonewt::Stonewt(int stone, double pounds) {
	stone_ = stone;
	pds_left_ = pounds;
	pounds_ = stone * Lbs_per_stn + pounds;
	type_ = stn_;
}

// destructor
Stonewt::~Stonewt() {

}

// public methods
// set type to stone
void Stonewt::set_stn() {
	type_ = stn_;
}

// set type to integer pound
void Stonewt::set_lbs_int() {
	type_ = lbs_int_;
}

// set type to double pound
void Stonewt::set_lbs_double() {
	type_ = lbs_double_;
}

// operator overloading
// overloading +
Stonewt Stonewt::operator+(const Stonewt& wt) const {
	Stonewt result(pounds_ + wt.pounds_);
	result.type_ = type_;

	return result;
}

// overloading -
Stonewt Stonewt::operator-(const Stonewt& wt) const {
	Stonewt result(pounds_ - wt.pounds_);
	result.type_ = type_;

	return result;
}

// overloading *
Stonewt Stonewt::operator*(double n) const {
	Stonewt result(n * pounds_);
	result.type_ = type_;

	return result;
}

// friends
// overloading *
Stonewt operator*(double n, const Stonewt& wt) {
	return wt * n;
}

// operator<< overloading
std::ostream& operator<<(std::ostream& os, const Stonewt& wt) {
	if (wt.type_ == Stonewt::stn_)
	{
		os << wt.stone_ << " stones, " << wt.pds_left_ << " pounds";
	}
	else if (wt.type_ == Stonewt::lbs_int_)
	{
		os << int(wt.pounds_ + 0.5) << " pounds";
	}
	else if (wt.type_ == Stonewt::lbs_double_)
	{
		os << wt.pounds_ << " pounds";
	}
	else
	{
		os << "Invalid type!";
	}

	return os;
}
