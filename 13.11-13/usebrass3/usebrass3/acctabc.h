// acctabc.h
// bank account classes

#pragma once

#include <iostream>
#include <string>

// Abstract Base Class
class AcctABC
{
public:
	AcctABC(const std::string& s = "Nullbody", long an = -1,
		double bal = 0.0);

	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;       // pure virtual function
	virtual void ViewAcct() const = 0;           // pure virtual function
	double Balance() const;

	virtual ~AcctABC();

private:
	std::string fullname_;
	long acctNum_;
	double balance_;

protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string& FullName() const;
	long AcctNum() const;
	Formatting SetFormat() const;
	void Restore(Formatting& f) const;
};

// Brass Account Class
class Brass : public AcctABC
{
public:
	Brass(const std::string& s = "Nullbody", long an = -1,
		double bal = 0.0);

	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;

	virtual ~Brass();
};

// Brass Plus Account Class
class BrassPlus : public AcctABC
{
public:
	BrassPlus(const std::string& s = "Nullbody", long an = -1,
		double bal = 0.0, double ml = 500,
		double r = 0.10);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.1);

	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	void ResetMax(double m);
	void ResetRate(double r);
	void ResetOwes();

	virtual ~BrassPlus();

private:
	double maxLoan_;
	double rate_;
	double owesBank_;
};
