// stock40.h
// char* instead of std::string

#pragma once

#include <iostream>

class Stock
{
public:
	Stock();                           // default constructor
	Stock(const char* co, long n = 0, double pr = 0.0);
	~Stock();                          // do-nothing destructor

	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const Stock& topval(const Stock& s) const;

	friend std::ostream& operator<<(std::ostream& os, const Stock& st);

private:
	char* company_;
	int shares_;
	double share_val_;
	double total_val_;

	void set_tot();
};
