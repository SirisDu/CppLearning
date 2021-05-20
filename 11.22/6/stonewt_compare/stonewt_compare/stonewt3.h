// stonewt3.h
// definition for the Stonewt class

#pragma once

#include <iostream>

class Stonewt
{
public:
	Stonewt();                             // default constructor
	Stonewt(double pounds);                // constructor for double pounds
	Stonewt(int stone, double pounds);     // constructor for stone, pounds
	~Stonewt();

	void set_stn();                        // set type to stone
	void set_lbs_int();                    // set type to integer pound
	void set_lbs_double();                 // set type to double pound

	Stonewt operator+(const Stonewt& wt) const;
	Stonewt operator-(const Stonewt& wt) const;
	Stonewt operator*(double n) const;
	bool operator>(const Stonewt& wt) const;
	bool operator<(const Stonewt& wt) const;
	bool operator==(const Stonewt& wt) const;
	bool operator!=(const Stonewt& wt) const;
	bool operator>=(const Stonewt& wt) const;
	bool operator<=(const Stonewt& wt) const;

	friend Stonewt operator*(double n, const Stonewt& wt);
	friend std::ostream& operator<<(std::ostream& os, const Stonewt& wt);

private:
	enum { Lbs_per_stn = 14 };             // pounds per stone
	enum { stn_, lbs_int_, lbs_double_ };  // display types

	int stone_;                            // whole stones
	double pds_left_;                      // fractional pounds
	double pounds_;                        // entire weight in pounds
	int type_;
};
