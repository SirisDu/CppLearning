// exc_mean.h
// exception classes for hmean(), gmean()

#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class bad_hmean : public std::logic_error
{
public:
	bad_hmean(std::string s = "bad_hmean -- Invalid argument: a = -b\n")
		: std::logic_error(s) {}
};

class bad_gmean : public std::logic_error
{
public:
	bad_gmean(std::string s =
		"bad_gmean -- gmean() arguments should be >= 0\n")
		: std::logic_error(s) {}
};
