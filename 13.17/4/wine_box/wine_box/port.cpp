// port.cpp
// Port and VintagePort methods

#include <cstring>
#include "port.h"

// base Port class
// constructors and destructor
// default constructor
Port::Port(const char* brand, const char* style, int bottles) {
	size_t brand_len{ strlen(brand) };

	brand_ = new char[brand_len + 1];
	strcpy_s(brand_, brand_len + 1, brand);
	strcpy_s(style_, 20, style);
	bottles_ = bottles;
}

// copy constructor
Port::Port(const Port& port) {
	size_t brand_len{ strlen(port.brand_) };

	brand_ = new char[brand_len + 1];
	strcpy_s(brand_, brand_len + 1, port.brand_);
	strcpy_s(style_, 20, port.style_);
	bottles_ = port.bottles_;
}

// destructor
Port::~Port() {
	delete[] brand_;
}
// end constructors and destructor

// normal methods
// show bottle count
int Port::BottleCount() const {
	return bottles_;
}

// show all information
void Port::Show() const {
	std::cout << brand_ << ", " << style_ << ", " << bottles_;
}
// end normal methods

// operator overload
// assignment overload
Port& Port::operator=(const Port& port) {
	if (this == & port)
	{
		return *this;
	}
	else
	{
		delete[] brand_;
		size_t brand_len{ strlen(port.brand_) };

		strcpy_s(brand_, brand_len + 1, port.brand_);
		strcpy_s(style_, 20, port.style_);
		bottles_ = port.bottles_;

		return *this;
	}
}

// adds bottle to bottle_
Port& Port::operator+=(int bottles) {
	bottles_ += bottles;

	return *this;
}

// subtract bottle from bottle_, if available
Port& Port::operator-=(int bottles) {
	if (bottles_ < bottles)
	{
		std::cout << "No enough bottles, subtract canceled." << std::endl;
	}
	else
	{
		bottles_ -= bottles;
	}

	return *this;
}
// end operator overload

// friend
// overload <<
std::ostream& operator<<(std::ostream& os, const Port& port) {
	os << port.brand_ << ", " << port.style_ << ", " << port.bottles_;

	return os;
}
// end friend
// end base Port methods

// derived VintagePort methods
// constructors and destructor
// default constructor
VintagePort::VintagePort() : Port("", "vintage", 0) {
	nickname_ = new char[1];
	nickname_[0] = '\0';
	year_ = 0;
}

// custom constructor
VintagePort::VintagePort(const char* brand, int bottles,
	const char* nickname, int year) : Port(brand, "vintage", bottles) {
	nickname_ = new char[strlen(nickname) + 1];
	strcpy_s(nickname_, strlen(nickname) + 1, nickname);
	year_ = year;
}

// copy constructor
VintagePort::VintagePort(const VintagePort& vintage) : Port(vintage) {
	nickname_ = new char[strlen(vintage.nickname_) + 1];
	strcpy_s(nickname_, strlen(vintage.nickname_) + 1, vintage.nickname_);
	year_ = vintage.year_;
}

// destructor
VintagePort::~VintagePort() {
	delete[] nickname_;
}
// end constructors and destructor

// normal method
// show vintage information
void VintagePort::Show() const {
	std::cout << (Port)(*this) << ", " << nickname_ << ", " << year_;
}
// end normal method

// operator overload
// assignment overload
VintagePort& VintagePort::operator=(const VintagePort& vintage) {
	if (this == &vintage)
	{
		return *this;
	}
	else
	{
		Port::operator=(vintage);

		delete[] nickname_;

		nickname_ = new char[strlen(vintage.nickname_) + 1];
		strcpy_s(nickname_, strlen(vintage.nickname_) + 1, vintage.nickname_);
		year_ = vintage.year_;

		return *this;
	}
}
// end operator overload

// friend
// << overload
std::ostream& operator<<(std::ostream& os, const VintagePort& vintage) {
	os << (Port)(vintage) << ", "
		<< vintage.nickname_ << ", " << vintage.year_;

	return os;
}
// end friend
// end derived VintagePort class
