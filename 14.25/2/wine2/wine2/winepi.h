// winepi.h
// Wine class using private inheritance

#pragma once

#include <string>
#include <valarray>
#include "pairs.h"

typedef Pair<std::valarray<int>, std::valarray<int>> PairArray;

class Wine : private std::string, private PairArray
{
public:
	// initialize label to l, number of years to y,
	// vintage years to yr[], bottles to bot[]
	Wine(const char* l, int y, const int yr[], const int bot[])
		: std::string(l), years_(y),
		PairArray(std::valarray<int>(yr, y), std::valarray<int>(bot, y))
	{}
	// intialize label to l, number of years to y,
	// create array objects of length y
	Wine(const char* l, int y) : std::string(l), years_(y),
		PairArray(std::valarray<int>(y), std::valarray<int>(y)) {}
	~Wine() {}

	void GetBottles();
	void Show() const;
	const std::string& Label() const { return (const std::string&)(*this); }
	int sum() const;

private:
	int years_;
};
