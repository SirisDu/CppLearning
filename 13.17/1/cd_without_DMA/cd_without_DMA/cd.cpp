// cd.cpp
// Cd and Classic methods

#include <iostream>
#include <cstring>
#include "cd.h"

// base class methods
// default constructor
Cd::Cd(const char* performers, const char* label, int selections,
	double playtime_in_minutes) {
	strcpy_s(performers_, 50, performers);
	strcpy_s(label_, 20, label);
	selections_ = selections;
	playtime_ = playtime_in_minutes;
}

// copy constructor
Cd::Cd(const Cd& disk) {
	strcpy_s(performers_, 50, disk.performers_);
	strcpy_s(label_, 20, disk.label_);
	selections_ = disk.selections_;
	playtime_ = disk.playtime_;
}

// destructor
Cd::~Cd() {

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
		strcpy_s(performers_, 50, disk.performers_);
		strcpy_s(label_, 20, disk.label_);
		selections_ = disk.selections_;
		playtime_ = disk.playtime_;

		return *this;
	}
}

// derived class methods
// default constructor
Classic::Classic(const char* main_works, const char* performers,
	const char* label, int selections, double playtime_in_minutes)
	: Cd(performers, label, selections, playtime_in_minutes) {
	strcpy_s(main_works_, 80, main_works);
}

// copy constructor
Classic::Classic(const Classic& disk) : Cd(disk) {
	strcpy_s(main_works_, 80, disk.main_works_);
}

// destructor
Classic::~Classic() {

}

// Classic CD report
void Classic::Report() const {
	std::cout << "Main Works: " << main_works_ << std::endl;
	Cd::Report();
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
		strcpy_s(main_works_, 80, disk.main_works_);

		return *this;
	}
}
