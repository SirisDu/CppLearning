// mytime4.cpp
// implementing Time methods

#include "mytime4.h"

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

// operator overloading using friends
// overload +
Time operator+(const Time& t1, const Time& t2) {
	Time sum;

	sum.minutes_ = t1.minutes_ + t2.minutes_;
	sum.hours_ = t1.hours_ + t2.hours_ + sum.minutes_ / 60;
	sum.minutes_ %= 60;

	return sum;
}

// overload -
Time operator-(const Time& t1, const Time& t2) {
	Time diff;
	int tot1, tot2;

	tot1 = t1.minutes_ + 60 * t1.hours_;
	tot2 = t2.minutes_ + 60 * t2.hours_;
	diff.minutes_ = (tot1 - tot2) % 60;
	diff.hours_ = (tot1 - tot2) / 60;

	return diff;
}

// overload *
Time operator*(const Time& t, double n) {
	Time result;
	long totalminutes;

	totalminutes = t.hours_ * n * 60 + t.minutes_ * n;
	result.hours_ = totalminutes / 60;
	result.minutes_ = totalminutes % 60;

	return result;
}

// overload *
Time operator*(double n, const Time& t) {
	return t * n;
}

// overload <<
std::ostream& operator<<(std::ostream& os, const Time& t) {
	os << t.hours_ << " hours, " << t.minutes_ << " minutes";

	return os;
}
