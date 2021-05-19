// stonewt.h
// definition for the Stonewt class

#pragma once

class Stonewt
{
public:
	Stonewt();                          // default constructor
	Stonewt(double pounds);             // constructor for double pounds
	Stonewt(int stone, double pounds);  // constructor for stone, pounds
	~Stonewt();

	void show_lbs() const;              // show weight in pounds format
	void show_stn() const;              // show weight in stone format

private:
	enum{Lbs_per_stn = 14};             // pounds per stone
	int stone_;                         // whole stones
	double pds_left_;                   // fractional pounds
	double pounds_;                     // entire weight in pounds
};
