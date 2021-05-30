// cd.h
// Cd class

#pragma once

// base class
class Cd                                         // represents a CD disk
{
public:
	Cd(const char* performers = "no one", const char* label = "nothing",
		int selections = 0, double playtime_in_minutes = 0.0);
	Cd(const Cd& disk);
	virtual ~Cd();

	virtual void Report() const;                 // reports all CD data
	Cd& operator=(const Cd& disk);

private:
	char* performers_;
	char* label_;
	int selections_;                             // number of selections
	double playtime_;                            // playing time in minutes
};
