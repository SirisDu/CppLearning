// brass.h
// bank account classes

#pragma once

#include <string>

// Brass Account Class
class Brass
{
public:
	Brass(const std::string& s = "Nullbody", long acctNum = -1,
		double balance = 0.0);
	virtual ~Brass();

	void Deposit(double amt);
	double Balance() const;
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;

private:
	std::string fullname_;
	long acctNum_;
	double balance_;
};

// Brass Plus Account class
class BrassPlus : public Brass
{
public:
	BrassPlus(const std::string& s = "Nullbody", long acctNum = -1,
		double balance = 0.0, double ml = 500,
		double r = 0.11125);
	BrassPlus(const Brass& ba, double ml = 500,
		double r = 0.11125);
	~BrassPlus();

	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	void ResetMax(double m);
	void ResetRate(double r);
	void ResetOwes();

private:
	double maxLoan_;
	double rate_;
	double owesBank_;
};
