// strngbad.cpp
// StringBad class methods

#include <cstring>
#include "strngbad.h"

// initializing static class member
int StringBad::num_strings_{ 0 };

// class methods
// default constructor
StringBad::StringBad() {
	len_ = 4;
	str_ = new char[4];
	strcpy_s(str_, 4, "C++");                          // default string
	std::cout << num_strings_ << ": \"" << str_
		<< "\" default object created" << std::endl;   // For Your Information
}

// construct StringBad from C string
StringBad::StringBad(const char* str) {
	len_ = std::strlen(str);                           // set size
	str_ = new char[len_ + 1];                         // allocate storage
	strcpy_s(str_, len_ + 1, str);                            // initialize pointer
	++num_strings_;                                    // set object count
	std::cout << num_strings_ << ": \"" << str_
		<< "\" object created" << std::endl;           // FYI
}

// necessary destructor
StringBad::~StringBad() {
	std::cout << "\"" << str_ << "\" object deleted, ";// FYI
	--num_strings_;                                    // required
	std::cout << num_strings_ << " left" << std::endl; // FYI
	delete[] str_;                                     // required
}

std::ostream& operator<<(std::ostream& os, const StringBad& str) {
	os << str.str_;

	return os;
}
