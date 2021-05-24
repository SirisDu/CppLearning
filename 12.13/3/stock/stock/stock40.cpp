// stock40.cpp
// Stock class methods

#include <cstring>
#include "stock40.h"

// constructors
Stock::Stock() {                        // default constructor
	company_ = new char[1];
	company_[0] = '\0';
	shares_ = 0;
	share_val_ = 0.0;
	total_val_ = 0.0;
}

Stock::Stock(const char* co, long n, double pr) {
	int length = strlen(co);
	company_ = new char[length + 1];
	strcpy_s(company_, length + 1, co);
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
Stock::~Stock() {
	delete[] company_;
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

std::ostream& operator<<(std::ostream& os, const Stock& st) {
	// set format to #.###
	std::ios_base::fmtflags orig =
		os.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::streamsize prec = os.precision(3);

	os << "Company: " << st.company_
		<< "  Shares: " << st.shares_ << std::endl;
	os << "  Share Price: $" << st.share_val_;
	// set format to #.##
	os.precision(2);
	os << "  Total Worth: $" << st.total_val_ << std::endl;

	// restore to original format
	os.setf(orig, std::ios_base::floatfield);
	os.precision(prec);

	return os;
}

// private method
void Stock::set_tot() {
	total_val_ = shares_ * share_val_;
}
