// newexcp.cpp
// the bad_alloc exception

#include <iostream>
#include <new>
#include <cstdlib>

struct Big
{
    double stuff[20000];
};

struct BigBig
{
	Big bigstuff[1000];
};

int main()
{
    BigBig* pd;
	try
	{
		std::cout << "Trying to get a big block of memory:" << std::endl;
		pd = new BigBig[10000];
		std::cout << "Got past the new requst:" << std::endl;
	}
	catch (std::bad_alloc& ba)
	{
		std::cout << "Caught the exception!" << std::endl;
		std::cout << ba.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Memory suceesfully allocated" << std::endl;
	pd[0].bigstuff[0].stuff[0] = 4;
	std::cout << pd[0].bigstuff[0].stuff[0] << std::endl;
	delete[] pd;
}
