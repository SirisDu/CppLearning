// classic.h
// Classic class

#pragma once

#include "cd.h"

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
	char* main_works_;
};
