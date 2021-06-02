// arraytp.h
// Array template

#pragma once

#include <iostream>
#include <cstdlib>

template <typename T, int n>
class ArrayTP
{
public:
	ArrayTP() {};
	explicit ArrayTP(const T& v);
	virtual ~ArrayTP() {};

	virtual T& operator[](int n);
	virtual T operator[](int n) const;

private:
	T ar[n];
};

template <typename T, int n>
ArrayTP<T, n>::ArrayTP(const T& v)
{
	for (int i = 0; i < n; i++)
	{
		ar[i] = v;
	}
}

template <typename T, int n>
T& ArrayTP<T, n>::operator[](int i)
{
	if (i < 0 || i >= n)
	{
		std::cerr << "Error in array limits: " << i
			<< " is out of range" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	return ar[i];
}

template <typename T, int n>
T ArrayTP<T, n>::operator[](int i) const
{
	if (i < 0 || i >= n)
	{
		std::cerr << "Error in array limits: " << i
			<< " is out of range" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	return ar[i];
}
