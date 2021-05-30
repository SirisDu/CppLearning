// classic.cpp
// Classic methods

#include <iostream>
#include <cstring>
#include "classic.h"

// derived class methods
// default constructor
Classic::Classic(const char* main_works, const char* performers,
	const char* label, int selections, double playtime_in_minutes)
	: Cd(performers, label, selections, playtime_in_minutes) {
	size_t length{ strlen(main_works) };

	main_works_ = new char[length + 1];
	strcpy_s(main_works_, length + 1, main_works);
}

// copy constructor
Classic::Classic(const Classic& disk) : Cd(disk) {
	size_t length{ strlen(disk.main_works_) };

	main_works_ = new char[length + 1];
	strcpy_s(main_works_, length + 1, disk.main_works_);
}

// destructor
Classic::~Classic() {
	delete[] main_works_;
}

// Classic CD report
void Classic::Report() const {
	Cd::Report();
	std::cout << "Main Works: " << main_works_ << std::endl;
}

// assignment overload
Classic& Classic::operator=(const Classic& disk) {
	if (this == &disk)
	{
		return *this;
	}
	else
	{
		Cd::operator=(disk);

		size_t length{ strlen(disk.main_works_) };

		main_works_ = new char[length + 1];
		strcpy_s(main_works_, length + 1, disk.main_works_);

		return *this;
	}
}
