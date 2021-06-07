// tv.cpp
// methods for the Tv class (Remote methods are inline)

#include <iostream>
#include "tv.h"

bool Tv::volup()
{
	if (volume_ < MaxVal)
	{
		++volume_;
		return true;
	}
	else
	{
		return false;
	}
}

bool Tv::voldown()
{
	if (volume_ > MinVal)
	{
		--volume_;
		return true;
	}
	else
	{
		return false;
	}
}

void Tv::chanup()
{
	if (channel_ < maxchannel_)
	{
		++channel_;
	}
	else
	{
		channel_ = 1;
	}
}

void Tv::chandown()
{
	if (channel_ > 1)
	{
		--channel_;
	}
	else
	{
		channel_ = maxchannel_;
	}
}

void Tv::settings() const
{
	using namespace std;
	cout << "TV is " << (state_ == Off ? "Off" : "On") << endl;
	if (state_ == On)
	{
		cout << "Volume setting = " << volume_ << endl;
		cout << "Channel setting = " << channel_ << endl;
		cout << "Mode = " << (mode_ == Antenna ? "antenna" : "cable") << endl;
		cout << "Input = " << (input_ == TV ? "TV" : "DVD") << endl;
	}
}
