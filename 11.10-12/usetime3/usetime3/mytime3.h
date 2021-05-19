// mytime3.h
// Time class with friends

#pragma once

#include <iostream>

class Time
{
public:
	Time();
	Time(int hours, int minutes = 0);
	~Time();

	void AddMin(int minutes);
	void AddHr(int hours);
	void Reset(int hours, int minutes = 0);

	Time operator+(const Time& t) const;
	Time operator-(const Time& t) const;
	Time operator*(double n) const;

	friend Time operator*(double n, const Time& t);
	friend std::ostream& operator<<(std::ostream& os, const Time& t);

private:
	int hours_;
	int minutes_;
};
