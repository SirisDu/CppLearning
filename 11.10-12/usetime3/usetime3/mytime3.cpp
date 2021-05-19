// mytime3.cpp
// implementing Time methods

#include "mytime3.h"

// constructors and destructor
// default constructor
Time::Time() {
	hours_ = minutes_ = 0;
}

// constructor for initialization
Time::Time(int hours, int minutes) {
	hours_ = hours;
	minutes_ = minutes;
}

// destructor
Time::~Time() {

}

// public methods
// add to minutes
void Time::AddMin(int minutes) {
	minutes_ += minutes;
	hours_ += minutes_ / 60;
	minutes_ %= 60;
}

// add to hours
void Time::AddHr(int hours) {
	hours_ += hours;
}

// reset
void Time::Reset(int hours, int minutes) {
	hours_ = hours;
	minutes_ = minutes;
}

// operator overloading
// overload +
Time Time::operator+(const Time& t) const {
	Time sum;

	sum.minutes_ = minutes_ + t.minutes_;
	sum.hours_ = hours_ + t.hours_ + sum.minutes_ / 60;
	sum.minutes_ %= 60;

	return sum;
}

// overload -
Time Time::operator-(const Time& t) const {
	Time diff;
	int tot1, tot2;

	tot1 = t.minutes_ + 60 * t.hours_;
	tot2 = minutes_ + 60 * hours_;
	diff.minutes_ = (tot2 - tot1) % 60;
	diff.hours_ = (tot2 - tot1) / 60;

	return diff;
}

// overload *
Time Time::operator*(double n) const {
	Time result;
	long totalminutes;

	totalminutes = hours_ * n * 60 + minutes_ * n;
	result.hours_ = totalminutes / 60;
	result.minutes_ = totalminutes % 60;

	return result;
}

// friends
// overload *
Time operator*(double n, const Time& t) {
	return t * n;
}

// overload <<
std::ostream& operator<<(std::ostream& os, const Time& t) {
	os << t.hours_ << " hours, " << t.minutes_ << " minutes";

	return os;
}
