// port.h
// Port class

#pragma once

#include <iostream>

class Port
{
public:
	Port(const char* brand = "none", const char* style = "none",
		int bottles = 0);
	Port(const Port& port);       // copy constructor
	virtual ~Port();

	int BottleCount() const;
	virtual void Show() const;

	Port& operator=(const Port& port);
	Port& operator+=(int bottles);// adds bottle to bottle_
	Port& operator-=(int bottles);// subtract bottle from bottle_, if available

	friend std::ostream& operator<<(std::ostream& os, const Port& port);

private:
	char* brand_;
	char style_[20];              // i.e., tawny, ruby, vintage
	int bottles_;
};

class VintagePort :public Port    // style necessarily = "vintage"
{
public:
	VintagePort();
	VintagePort(const char* brand, int bottles,
		const char* nickname, int year);
	VintagePort(const VintagePort& vintage);
	~VintagePort();

	void Show() const;

	VintagePort& operator=(const VintagePort& vintage);

	friend std::ostream& operator<<
		(std::ostream& os, const VintagePort& vintage);

private:
	char* nickname_;              // i.e., "The Noble" or "Old Velvet", etc
	int year_;                    // vintage year
};
