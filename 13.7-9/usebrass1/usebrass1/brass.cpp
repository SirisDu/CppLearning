// brass.cpp
// bank account class methods

#include <iostream>
#include "brass.h"

// formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format setFormat() {
	// set up ###.## format
	return std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p) {
	std::cout.setf(f, std::ios_base::floatfield);
	std::cout.precision(p);
}

// Brass methods
Brass::Brass(const std::string& s, long acctNum, double balance) {
	fullname_ = s;
	acctNum_ = acctNum;
	balance_ = balance;
}

Brass::~Brass() {

}

void Brass::Deposit(double amt) {
	if (amt < 0)
	{
		std::cout << "Negative deposit not allowed;"
			" deposit canceled." << std::endl;
	}
	else
	{
		balance_ += amt;
	}
}

double Brass::Balance() const {
	return balance_;
}

void Brass::Withdraw(double amt) {
	// set up ###.## format
	format initialState = setFormat();
	precis prec = std::cout.precision(2);

	if (amt < 0)
	{
		std::cout << "Withdrawal amount must be positive;"
			" withdrawal canceled." << std::endl;
	}
	else if (amt <= balance_)
	{
		balance_ -= amt;
	}
	else
	{
		std::cout << "Withdrawal amount of $" << amt
			<< " exceeds your balance." << std::endl
			<< "Withdraw canceled." << std::endl;
	}
	restore(initialState, prec);
}

void Brass::ViewAcct() const {
	// set up ###.## format
	format initialState = setFormat();
	precis prec = std::cout.precision(2);

	std::cout << "Client: " << fullname_ << std::endl;
	std::cout << "Account Number: " << acctNum_ << std::endl;
	std::cout << "Balance: $" << balance_ << std::endl;
	restore(initialState, prec);
}

// BrassPlus methods
BrassPlus::BrassPlus(const std::string& s, long acctNum, double balance,
	double ml, double r) : Brass(s, acctNum, balance) {
	maxLoan_ = ml;
	owesBank_ = 0.0;
	rate_ = r;
}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r)
	: Brass(ba) {                      // use implicit copy constructor
	maxLoan_ = ml;
	owesBank_ = 0.0;
	rate_ = r;
}

BrassPlus::~BrassPlus() {

}

// redifine how Withdraw() works
void BrassPlus::Withdraw(double amt) {
	// set up ###.## format
	format initialState = setFormat();
	precis prec = std::cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
	{
		Brass::Withdraw(amt);
	}
	else if (amt <= bal + maxLoan_ - owesBank_)
	{
		double advance = amt - bal;
		owesBank_ += advance * (1.0 + rate_);
		std::cout << "Bank advance: $" << advance << std::endl;
		std::cout << "Finance charge: $" << advance * rate_ << std::endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
	{
		std::cout << "Credit limit exceeded. Transaction cancelled."
			<< std::endl;
	}
	restore(initialState, prec);
}

// redifine how ViewAcct() works
void BrassPlus::ViewAcct() const {
	// set up ###.## format
	format initialState = setFormat();
	precis prec = std::cout.precision(2);

	Brass::ViewAcct();                 // display base portion
	std::cout << "Maximum loan: $" << maxLoan_ << std::endl;
	std::cout << "Owed to bank: $" << owesBank_ << std::endl;
	std::cout.precision(3);            // ###.### format
	std::cout << "Loan Rate: " << 100 * rate_ << "%" << std::endl;
	restore(initialState, prec);
}

void BrassPlus::ResetMax(double m) {
	maxLoan_ = m;
}

void BrassPlus::ResetRate(double r) {
	rate_ = r;
}

void BrassPlus::ResetOwes() {
	owesBank_ = 0.0;
}
