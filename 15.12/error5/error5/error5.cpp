// error5.cpp
// unwinding the stack

#include <iostream>
#include <cmath>
#include <string>
#include "exc_mean.h"

class demo
{
public:
	demo(const std::string& str)
	{
		word = str;
		std::cout << "demo " << word << " created" << std::endl;
	}
	~demo()
	{
		std::cout << "demo " << word << " destroyed" << std::endl;
	}

	void show() const
	{
		std::cout << "demo " << word << " lives!" << std::endl;
	}

private:
	std::string word;
};

// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main()
{
	double x, y, z;
	{
		demo d1("found in block in main()");
		std::cout << "Enter two numbers: ";
		while (std::cin >> x >> y)
		{
			try                    // start of try block
			{
				z = means(x, y);
				std::cout << "The mean mean of " << x << " and " << y
					<< " is " << z << std::endl;
				std::cout << "Enter next pair: ";
			}                      // end of try block
			catch (bad_hmean& bg)  // start of catch block
			{
				bg.mesg();
				std::cout << "Try again." << std::endl;
				continue;
			}
			catch (bad_gmean& hg)
			{
				std::cout << hg.mesg();
				std::cout << "Value used: " << hg.v1 << ", " << hg.v2
					<< std::endl;
				std::cout << "Sorry, you don't get to play anymore."
					<< std::endl;
				break;
			}                      // end of catch block
		}
		d1.show();
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

double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b) / 2.0;            // arithmetic mean
	try
	{
		hm = hmean(a, b);
		gm = gmean(a, b);
	}
	catch (bad_hmean& bg)          // start of catch block
	{
		bg.mesg();
		std::cout << "Caught in means()" << std::endl;
		throw;                     // rethrow the exception
	}
	d2.show();
	return (am + hm + gm) / 3.0;
}
