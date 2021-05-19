// stonewt.cpp
// Stonewt methods

#include <iostream>
#include "stonewt.h"

// constructors and destructor
// default constructor, weight = 0
Stonewt::Stonewt() {
	stone_ = pounds_ = pds_left_ = 0;
}

// constructor Stonewt object from double value
Stonewt::Stonewt(double pounds) {
	stone_ = int(pounds) / Lbs_per_stn;       // integer division
	pds_left_ = int(pounds) % Lbs_per_stn + pounds - int(pounds);
	pounds_ = pounds;
}

// construc Stonewt object from stone, double values
Stonewt::Stonewt(int stone, double pounds) {
	stone_ = stone;
	pds_left_ = pounds;
	pounds_ = stone * Lbs_per_stn + pounds;
}

// destructor
Stonewt::~Stonewt() {

}

// public methods
// show weight in stones
void Stonewt::show_lbs() const {
	std::cout << pounds_ << " pounds" << std::endl;
	
}

// show weight in pounds
void Stonewt::show_stn() const {
	std::cout << stone_ << " stones, " << pds_left_ << " pounds" << std::endl;
}
