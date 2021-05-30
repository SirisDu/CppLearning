// cd.cpp
// cd methods

#include <iostream>
#include <cstring>
#include "cd.h"

// base class methods
// default constructor
Cd::Cd(const char* performers, const char* label, int selections,
	double playtime_in_minutes) {
	size_t length1{ strlen(performers) };
	size_t length2{ strlen(label) };

	performers_ = new char[length1 + 1];
	strcpy_s(performers_, length1 + 1, performers);
	label_ = new char[length2 + 1];
	strcpy_s(label_, length2 + 1, label);
	selections_ = selections;
	playtime_ = playtime_in_minutes;
}

// copy constructor
Cd::Cd(const Cd& disk) {
	size_t length1{ strlen(disk.performers_) };
	size_t length2{ strlen(disk.label_) };

	performers_ = new char[length1 + 1];
	strcpy_s(performers_, length1 + 1, disk.performers_);
	label_ = new char[length2 + 1];
	strcpy_s(label_, length2 + 1, disk.label_);
	selections_ = disk.selections_;
	playtime_ = disk.playtime_;
}

// destructor
Cd::~Cd() {
	delete[] performers_;
	delete[] label_;
}

// Cd report
void Cd::Report() const {
	std::cout << "Performers: " << performers_ << std::endl;
	std::cout << "     Label: " << label_ << std::endl;
	std::cout << "Selections: " << selections_ << std::endl;
	std::cout << "  Playtime: " << playtime_ << " mins" << std::endl;
}

// assignment overload
Cd& Cd::operator=(const Cd& disk) {
	if (this == &disk)
	{
		return *this;
	}
	else
	{
		size_t length1{ strlen(disk.performers_) };
		size_t length2{ strlen(disk.label_) };

		performers_ = new char[length1 + 1];
		strcpy_s(performers_, length1 + 1, disk.performers_);
		label_ = new char[length2 + 1];
		strcpy_s(label_, length2 + 1, disk.label_);
		selections_ = disk.selections_;
		playtime_ = disk.playtime_;

		return *this;
	}
}
