﻿// smrtptrs.cpp
// use three kinds of smart pointers

#include <iostream>
#include <string>
#include <memory>

class Report
{
public:
	Report(const std::string& s) : str(s)
	{
		std::cout << "Object created!" << std::endl;
	}
	~Report() { std::cout << "Object deleted!" << std::endl; }

	void comment() const { std::cout << str << std::endl; }

private:
	std::string str;
};

int main()
{
	{
		std::auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->comment();         // use -> to invoke a member function
	}
	{
		std::shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}
}
