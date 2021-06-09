// exc_mean2.cpp
// using a base exception class

#include <iostream>
#include <cmath>
#include "exc_means2.h"

// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	double x, y, z;

	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		try                                   // start of try block
		{
			z = hmean(x, y);
			std::cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << std::endl;
			std::cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean(x, y) << std::endl;
			std::cout << "Enter next set of numbers <q to quit>: ";
		}                                     // end of try block
		catch (base_mean& bm)
		{
			std::cout << "Invalid inputs: " << bm.val1 << ", " << bm.val2
				<< std::endl;
			std::cout << bm.what();
			std::cout << "Sorry, you don't get to play anymore." << std::endl;
			break;
		}                                    // end of catch block
	}
	std::cout << "Bye!" << std::endl;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		throw bad_hmean(a, b);
	}
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
	{
		throw bad_gmean(a, b);
	}
	return std::sqrt(a * b);
}
