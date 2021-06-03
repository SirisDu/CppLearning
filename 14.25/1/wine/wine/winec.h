// winec.h
// Wine class

#pragma once

#include <string>
#include <valarray>
#include "pairs.h"

class Wine
{
public:
	// initialize label to l, number of years to y,
	// vintage years to yr[], bottles to bot[]
	Wine(const char* l, int y, const int yr[], const int bot[])
		: label_(l), years_(y),
		bottles_in_year_(std::valarray<int>(yr, y), std::valarray<int>(bot, y))
	{}
	// intialize label to l, number of years to y,
	// create array objects of length y
	Wine(const char* l, int y) : label_(l), years_(y),
		bottles_in_year_(std::valarray<int>(y), std::valarray<int>(y)) {}
	~Wine() {}

	void GetBottles();
	void Show() const;
	const std::string& Label() const { return label_; }
	int sum() const;

private:
	std::string label_;
	Pair<std::valarray<int>, std::valarray<int>> bottles_in_year_;
	int years_;
};
