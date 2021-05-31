// worker0.cpp
// working class methods

#include <iostream>
#include "worker0.h"

// Worker methods
// default constructor
Worker::Worker() : fullname_("no one"), id_(0L)
{

}

Worker::Worker(const std::string& s, long n) : fullname_(s), id_(n)
{

}

// must implement virtual destructor, even if pure
Worker::~Worker()
{

}

void Worker::Set()
{
	std::cout << "Enter worker's name: ";
	std::getline(std::cin, fullname_);
	std::cout << "Enter worker's ID: ";
	std::cin >> id_;
	while (std::cin.get() != '\n')
	{
		continue;
	}
}

void Worker::Show() const
{
	std::cout << "Name: " << fullname_ << std::endl;
	std::cout << "Employee ID: " << id_ << std::endl;
}

// Waiter methods
Waiter::Waiter() : Worker(), panache_(0)
{

}

Waiter::Waiter(const std::string& s, long n, int p) : Worker(s, n), panache_(p)
{

}

Waiter::Waiter(const Worker& wk, int p) : Worker(wk), panache_(p)
{

}

Waiter::~Waiter()
{

}

void Waiter::Set()
{
	Worker::Set();
	std::cout << "Enter waiter's panache rating: ";
	std::cin >> panache_;
	while (std::cin.get() != '\n')
	{
		continue;
	}
}

void Waiter::Show() const
{
	std::cout << "Category: waiter" << std::endl;
	Worker::Show();
	std::cout << "Panache rating: " << panache_ << std::endl;
}

// Singer methods
Singer::Singer() : Worker(), voice_(other)
{

}

Singer::Singer(const std::string& s, long n, int v) : Worker(s, n), voice_(v)
{

}

Singer::Singer(const Worker& wk, int v) : Worker(wk), voice_(v)
{

}

Singer::~Singer()
{

}

const char* Singer::pv[] = { "other", "alto", "contralto",
	"soprano", "bass", "baritone", "tenor" };

void Singer::Set()
{
	Worker::Set();
	std::cout << "Enter number for singer's vocal range:" << std::endl;
	int i{};
	for (i = 0; i < Vtypes; i++)
	{
		std::cout << i << ": " << pv[i] << "   ";
		if (i % 4 == 3)
		{
			std::cout << std::endl;
		}
	}
	if (i % 4 != 0)
	{
		std::cout << std::endl;
	}
	while (std::cin >> voice_ && (voice_ < 0 || voice_ >= Vtypes))
	{
		std::cout << "Please enter a value >= 0 and < " << Vtypes << std::endl;
	}
	while (std::cin.get() != '\n')
	{
		continue;
	}
}

void Singer::Show() const
{
	std::cout << "Category: singer" << std::endl;
	Worker::Show();
	std::cout << "Vocal range: " << pv[voice_] << std::endl;
}
