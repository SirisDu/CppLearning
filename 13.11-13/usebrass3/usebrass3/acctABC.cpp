// acctABC.cpp
// bank account class methods

#include "acctabc.h"

// Abstract Base Class
AcctABC::AcctABC(const std::string& s, long an, double bal) {
	fullname_ = s;
	acctNum_ = an;
	balance_ = bal;
}

void AcctABC::Deposit(double amt) {
	if (amt < 0)
	{
		std::cout << "Negative deposit not allowed; "
			"deposit is canceled." << std::endl;
	}
	else
	{
		balance_ += amt;
	}
}

void AcctABC::Withdraw(double amt) {
	balance_ -= amt;
}

double AcctABC::Balance() const {
	return balance_;
}

AcctABC::~AcctABC() {

}

const std::string& AcctABC::FullName() const {
	return fullname_;
}

long AcctABC::AcctNum() const {
	return acctNum_;
}

// protected methods for formatting
AcctABC::Formatting AcctABC::SetFormat() const {
	// set up ###.## format
	Formatting f{};

	f.flag = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	f.pr = std::cout.precision(2);

	return f;
}

void AcctABC::Restore(Formatting& f) const {
	std::cout.setf(f.flag, std::ios_base::floatfield);
	std::cout.precision(f.pr);
}

// Brass methods
Brass::Brass(const std::string& s, long an, double bal) : AcctABC(s, an, bal) {

}

void Brass::Withdraw(double amt) {
	if (amt < 0)
	{
		std::cout << "Withdrawal amount must be positive; "
			"withdrawal canceled." << std::endl;
	}
	else if (amt <= Balance())
	{
		AcctABC::Withdraw(amt);
	}
	else
	{
		std::cout << "Withdrawal amount of $" << amt
			<< " exceeds your balance." << std::endl
			<< "Withdrawal canceled." << std::endl;
	}
}

void Brass::ViewAcct() const {
	Formatting f = SetFormat();
	std::cout << "Brass Client: " << FullName() << std::endl;
	std::cout << "Account Number: " << AcctNum() << std::endl;
	std::cout << "Balance: $" << Balance() << std::endl;
	Restore(f);
}

Brass::~Brass() {

}

// BrassPlus Methods
BrassPlus::BrassPlus(const std::string& s, long an, double bal,
	double ml, double r) : AcctABC(s, an, bal) {
	maxLoan_ = ml;
	owesBank_ = 0.0;
	rate_ = r;
}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r)
	: AcctABC(ba) {                   // uses implicit copy constructor
	maxLoan_ = ml;
	owesBank_ = 0.0;
	rate_ = r;
}

void BrassPlus::Withdraw(double amt) {
	Formatting f = SetFormat();
	double bal = Balance();

	if (amt <= bal)
	{
		AcctABC::Withdraw(amt);
	}
	else if (amt <= bal + maxLoan_ - owesBank_)
	{
		double advance = amt - bal;
		owesBank_ += advance * (1.0 + rate_);
		std::cout << "Bank advance: $" << advance << std::endl;
		std::cout << "Finance charge: $" << advance * rate_ << std::endl;
		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
	{
		std::cout << "Credit limit exceeded. Transaction canceled." << std::endl;
	}
	Restore(f);
}

void BrassPlus::ViewAcct() const {
	Formatting f = SetFormat();

	std::cout << "BrassPlus Client: " << FullName() << std::endl;
	std::cout << "Account Number: " << AcctNum() << std::endl;
	std::cout << "Balance: $" << Balance() << std::endl;
	std::cout << "Maximum loan: $" << maxLoan_ << std::endl;
	std::cout << "Owed to bank: $" << owesBank_ << std::endl;
	std::cout.precision(3);
	std::cout << "Loan Rate: " << 100 * rate_ << "%" << std::endl;
	Restore(f);
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

BrassPlus::~BrassPlus() {

}
