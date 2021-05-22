// strngbad.h
// flawed string class definition

#pragma once

#include <iostream>

class StringBad
{
public:
	StringBad();                    // default constructor
	StringBad(const char* str);     // constructor
	~StringBad();                   // destructor

	// friend function
	friend std::ostream& operator<<(std::ostream& os,
		const StringBad& str);

private:
	char* str_;                     // pointer to string
	int len_;                       // length of string
	static int num_strings_;        // number of objects
};
