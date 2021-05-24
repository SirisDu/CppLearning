// stock20.h
// augmented version

#pragma once

#include <string>

class Stock
{
public:
	Stock();                           // default constructor
	Stock(const std::string& co, long n = 0, double pr = 0.0);
	~Stock();                          // do-nothing destructor

	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	const Stock& topval(const Stock& s) const;

private:
	std::string company_;
	int shares_;
	double share_val_;
	double total_val_;

	void set_tot();
};
