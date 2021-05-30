// cd.h
// base Cd class and derived Classic class

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
	char performers_[50];
	char label_[20];
	int selections_;                             // number of selections
	double playtime_;                            // playing time in minutes
};

// derived class
class Classic : public Cd                        // represents a Classic CD
{
public:
	Classic(const char* main_works = "none", const char* performers = "no one",
		const char* label = "nothing", int selections = 0,
		double playtime_in_minutes = 0.0);
	Classic(const Classic& disk);
	virtual ~Classic();

	virtual void Report() const;                 // reports all Classic CD data
	Classic& operator=(const Classic& disk);

private:
	char main_works_[80];
};
