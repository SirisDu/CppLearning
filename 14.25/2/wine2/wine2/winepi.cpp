// winepi.cpp
// Wine methods

#include <iostream>
#include "winepi.h"

// solicit input for year, bottle count
void Wine::GetBottles()
{
	std::cout << "Enter " << (const std::string&)(*this) << " data for "
		<< years_ << " year(s):" << std::endl;
	for (int i = 0; i < years_; i++)
	{
		std::cout << "Enter year: ";
		std::cin >> ((PairArray&)*this).first()[i];
		std::cout << "Enter bottles for that year: ";
		std::cin >> ((PairArray&)*this).second()[i];
	}
}

void Wine::Show() const
{
	std::cout << "Wine: " << (const std::string&)(*this) << std::endl;
	std::cout << "        Year    Bottles" << std::endl;
	for (int i = 0; i < years_; i++)
	{
		std::cout << "        " << ((PairArray&)*this).first()[i]
			<< "    " << ((PairArray&)*this).second()[i] << std::endl;
	}
}

int Wine::sum() const
{
	int _sum{};

	for (int i = 0; i < years_; i++)
	{
		_sum += ((PairArray&)*this).second()[i];
	}

	return _sum;
}
