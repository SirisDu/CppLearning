// workermi.cpp
// working class methods with MI

#include <iostream>
#include "workermi.h"

// Worker methods
Worker::Worker() : fullname_("no one"), id_(0L)
{

}

Worker::Worker(const std::string& s, long n) : fullname_(s), id_(n)
{

}

Worker::~Worker()
{

}

// protected methods
void Worker::Data() const
{
	std::cout << "Name: " << fullname_ << std::endl;
	std::cout << "Employee ID: " << id_ << std::endl;
}

void Worker::Get()
{
	std::getline(std::cin, fullname_);
	std::cout << "Enter worker's ID: ";
	std::cin >> id_;
	while (std::cin.get() != '\n')
	{
		continue;
	}
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
	std::cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	std::cout << "Category: waiter" << std::endl;
	Worker::Data();
	Data();
}

// protected methods
void Waiter::Data() const
{
	std::cout << "Panache rating: " << panache_ << std::endl;
}

void Waiter::Get()
{
	std::cout << "Enter waiter's panache rating: ";
	std::cin >> panache_;
	while (std::cin.get() != '\n')
	{
		continue;
	}
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
	std::cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	std::cout << "Category: singer" << std::endl;
	Worker::Data();
	Data();
}

// protected methods
void Singer::Data() const
{
	std::cout << "Vocal range: " << pv[voice_] << std::endl;
}

void Singer::Get()
{
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
	std::cin >> voice_;
	while (std::cin.get() != '\n')
	{
		continue;
	}
}

// SingerWaiter methods
SingerWaiter::SingerWaiter()
{

}

SingerWaiter::SingerWaiter(const std::string& s, long n, int p, int v)
	: Worker(s, n), Waiter(s, n, p), Singer(s, n, v)
{

}

SingerWaiter::SingerWaiter(const Worker& wk, int p, int v)
	: Worker(wk), Waiter(wk, p), Singer(wk, v)
{

}

SingerWaiter::SingerWaiter(const Waiter& wt, int v)
	: Worker(wt), Waiter(wt), Singer(wt, v)
{

}

SingerWaiter::SingerWaiter(const Singer& wt, int p)
	: Worker(wt), Waiter(wt, p), Singer(wt)
{

}

SingerWaiter::~SingerWaiter()
{

}

void SingerWaiter::Set()
{
	std::cout << "Enter singer waiter's name: ";
	Worker::Get();
	Get();
}

void SingerWaiter::Show() const
{
	std::cout << "Category: singing waiter:" << std::endl;
	Worker::Data();
	Data();
}

void SingerWaiter::Data() const
{
	Waiter::Data();
	Singer::Data();
}

void SingerWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}
