// mytime4.h
// overload all operators in Time with friends

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

	friend Time operator+(const Time& t1, const Time& t2);
	friend Time operator-(const Time& t1, const Time& t2);
	friend Time operator*(const Time& t, double n);
	friend Time operator*(double n, const Time& t);
	friend std::ostream& operator<<(std::ostream& os, const Time& t);

private:
	int hours_;
	int minutes_;
};
