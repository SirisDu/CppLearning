// exc_means2.h
// exception classes derived from a base exception class

#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class base_mean : public std::logic_error
{
public:
	double val1;
	double val2;

	base_mean(double a, double b, std::string s) : val1(a), val2(b),
		std::logic_error(s) {}
};

class bad_hmean : public base_mean
{
public:
	bad_hmean(double a, double b,
		std::string s = "bad_hmean -- Invalid argument: a = -b\n")
		: base_mean(a, b, s) {}
};

class bad_gmean : public base_mean
{
public:
	bad_gmean(double a, double b,
		std::string s = "bad_gmean -- gmean() arguments should be >= 0\n")
		: base_mean(a, b, s) {}
};
