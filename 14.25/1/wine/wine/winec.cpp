// winec.cpp
// Wine methods

#include <iostream>
#include "winec.h"

// solicit input for year, bottle count
void Wine::GetBottles()
{
	std::cout << "Enter " << label_ << " data for "
		<< years_ << " year(s):" << std::endl;
	for (int i = 0; i < years_; i++)
	{
		std::cout << "Enter year: ";
		std::cin >> bottles_in_year_.first()[i];
		std::cout << "Enter bottles for that year: ";
		std::cin >> bottles_in_year_.second()[i];
	}
}

void Wine::Show() const
{
	std::cout << "Wine: " << label_ << std::endl;
	std::cout << "        Year    Bottles" << std::endl;
	for (int i = 0; i < years_; i++)
	{
		std::cout << "        " << bottles_in_year_.first()[i]
			<< "    " << bottles_in_year_.second()[i] << std::endl;
	}
}

int Wine::sum() const
{
	int _sum{};

	for (int i = 0; i < years_; i++)
	{
		_sum += bottles_in_year_.second()[i];
	}

	return _sum;
}
