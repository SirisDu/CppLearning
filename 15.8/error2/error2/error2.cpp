// error2.cpp
// returning an error code

#include <iostream>
#include <cfloat>

bool hmean(double a, double b, double* answer);

int main()
{
	double x, y, z;

	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		if (hmean(x, y, &z))
		{
			std::cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << std::endl;
		}
		else
		{
			std::cout << "One value should not be the negative "
				"of the other -- try again." << std::endl;
		}
		std::cout << "Enter next set of numbers <q to quit>: ";
	}
	std::cout << "Bye!" << std::endl;
}

bool hmean(double a, double b, double* answer)
{
	if (a == -b)
	{
		*answer = DBL_MAX;
		return false;
	}
	else
	{
		*answer = 2.0 * a * b / (a + b);
		return true;
	}
}
