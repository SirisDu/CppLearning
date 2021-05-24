// stock20.cpp
// augmented version

#include <iostream>
#include "stock20.h"

// constructors
Stock::Stock() {                        // default constructor
	company_ = "no name";
	shares_ = 0;
	share_val_ = 0.0;
	total_val_ = 0.0;
}

Stock::Stock(const std::string& co, long n, double pr) {
	company_ = co;
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; "
			<< company_ << " shares set to 0." << std::endl;
		shares_ = 0;
	}
	else
	{
		shares_ = n;
	}
	share_val_ = pr;
	set_tot();
}

// class destructor
Stock::~Stock() {                       // quiet destructor

}

// other methods
void Stock::buy(long num, double price) {
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative. "
			"Transaction is aborted." << std::endl;
	}
	else
	{
		shares_ += num;
		share_val_ = price;
		set_tot();
	}
}

void Stock::sell(long num, double price) {
	if (num < 0)
	{
		std::cout << "Number of shares sold can't be negative. "
			"Transaction is aborted." << std::endl;
	}
	else if (num > shares_)
	{
		std::cout << "You can't sell more than you have! "
			"Transaction is aborted." << std::endl;
	}
	else
	{
		shares_ -= num;
		share_val_ = price;
		set_tot();
	}
}

void Stock::update(double price) {
	share_val_ = price;
	set_tot();
}

void Stock::show() const {
	// set format to #.###
	std::ios_base::fmtflags orig =
		std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::streamsize prec = std::cout.precision(3);

	std::cout << "Company: " << company_
		<< "  Shares: " << shares_ << std::endl;
	std::cout << "  Share Price: $" << share_val_;
	// set format to #.##
	std::cout.precision(2);
	std::cout << "  Total Worth: $" << total_val_ << std::endl;

	// restore to original format
	std::cout.setf(orig, std::ios_base::floatfield);
	std::cout.precision(prec);
}

const Stock& Stock::topval(const Stock& s) const {
	if (s.total_val_ > total_val_)
	{
		return s;
	}
	else
	{
		return *this;
	}
}

// private method
void Stock::set_tot() {
	total_val_ = shares_ * share_val_;
}
