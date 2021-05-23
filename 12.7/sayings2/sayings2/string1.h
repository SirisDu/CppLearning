// string1.h
// fixed and augmented string class definition

#pragma once

#include <iostream>

class String
{
public:
	// constructors and other methods
	String();                          // default constructor
	String(const char* s);             // constructor
	String(const String& s);           // copy constructor
	~String();                         // destructor
	int length() const;

	// overloaded operator methods
	String& operator=(const String& s);
	String& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;

	// overloaded operator friends
	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend std::ostream& operator<<(std::ostream& os, const String& st);
	friend std::istream& operator>>(std::istream& is, String& st);

	// static function
	static int HowMany();

private:
	char* str_;                        // pointer to string
	int len_;                          // length of string
	static int num_strings_;           // number of objects
	static const int CINLIM{ 80 };     // cin input limit
};
