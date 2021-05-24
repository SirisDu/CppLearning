// cow.h
// Cow class definition

#pragma once

class Cow
{
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	Cow(const Cow& c);
	~Cow();

	void ShowCow() const;          // display all cow data

	Cow& operator=(const Cow& c);

private:
	char name[20];
	char* hobby;
	double weight;
};
