// string1.cpp
// String class methods

#include <cstring>
#include "string1.h"

// initializing static class member
int String::num_strings_{ 0 };

// static method
int String::HowMany() {
	return num_strings_;
}

// class methods
// default constructor
String::String() {
	len_ = 4;
	str_ = new char[1];
	str_[0] = '\0';                    // default string
	++num_strings_;
}

// construct String from C string
String::String(const char* s) {
	len_ = std::strlen(s);             // set string
	str_ = new char[len_ + 1];         // allocate storage
	strcpy_s(str_, len_ + 1, s);       // initialize pointer
	++num_strings_;                    // set object count
}

// copy constructor
String::String(const String& s) {
	++num_strings_;                    // handle static member update
	len_ = s.len_;                     // same length
	str_ = new char[len_ + 1];         // allocate space
	strcpy_s(str_, len_ + 1, s.str_);  // copy string to new location
}

// necessary destructor
String::~String() {
	--num_strings_;                    // required
	delete[] str_;                     // required
}

int String::length() const {
	return len_;
}

// overloaded operator methods
// assign a String to a String
String& String::operator=(const String& s) {
	if (this == &s)
	{
		return *this;
	}
	delete[] str_;
	len_ = s.len_;
	str_ = new char[len_ + 1];
	strcpy_s(str_, len_ + 1, s.str_);

	return *this;
}

// assign a C string to a String
String& String::operator=(const char* s) {
	delete[] str_;
	len_ = std::strlen(s);
	str_ = new char[len_ + 1];
	strcpy_s(str_, len_ + 1, s);

	return *this;
}

// read-write char access for non-const String
char& String::operator[](int i) {
	return str_[i];
}

// read-only char access for const String
const char& String::operator[](int i) const {
	return str_[i];
}

// overloaded operator friends
// compare if String1 < String2
bool operator<(const String& st1, const String& st2) {
	return (std::strcmp(st1.str_, st2.str_) < 0);
}

// compare if String1 > String2
bool operator>(const String& st1, const String& st2) {
	return st2 < st1;
}

// compare if String1 == String2
bool operator==(const String& st1, const String& st2) {
	return (std::strcmp(st1.str_, st2.str_) == 0);
}

// simple String output
std::ostream& operator<<(std::ostream& os, const String& st) {
	os << st.str_;

	return os;
}

// quick and dirty String input
std::istream& operator>>(std::istream& is, String& st) {
	char temp[String::CINLIM]{};

	is.get(temp, String::CINLIM);
	if (is)
	{
		st = temp;
	}
	while (is && is.get() != '\n')
	{
		continue;
	}

	return is;
}
