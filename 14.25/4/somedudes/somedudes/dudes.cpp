// dudes.cpp
// various Show(), Set() methods

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dudes.h"

void Person::Show() const
{
	std::cout << "Name: " << firstname_ << " " << lastname_ << std::endl;
}

void Person::Set()
{
	std::string ln, fn;

	std::cout << "Enter lastname: ";
	std::getline(std::cin, ln);
	std::cout << "Enter firstname: ";
	std::getline(std::cin, fn);

	*this = Person(ln, fn);
}

void Gunslinger::Show() const
{
	Person::Show();
	PartShow();
}

void Gunslinger::PartShow() const
{
	std::cout << "Draw time: " << draw_ << std::endl;
	std::cout << "Nicks: " << nick_ << std::endl;
}

void Gunslinger::Set()
{
	std::string ln, fn;
	double draw;
	int nick;

	std::cout << "Enter lastname: ";
	std::getline(std::cin, ln);
	std::cout << "Enter firstname: ";
	std::getline(std::cin, fn);
	std::cout << "Enter draw time: ";
	std::cin >> draw;
	std::cout << "Enter nicks: ";
	std::cin >> nick;

	*this = Gunslinger(ln, fn, draw, nick);
}

void PokerPlayer::Show() const
{
	Person::Show();
	PartShow();
}

void PokerPlayer::PartShow() const
{
	std::cout << "Poker Card: " << poker_ << std::endl;
}

void PokerPlayer::Set()
{
	srand(time(0));
	std::string ln, fn;
	int poker{ rand() % 52 + 1 };

	std::cout << "Enter lastname: ";
	std::getline(std::cin, ln);
	std::cout << "Enter firstname: ";
	std::getline(std::cin, fn);

	*this = PokerPlayer(ln, fn, poker);
}

void BadDude::Show() const
{
	Person::Show();
	Gunslinger::PartShow();
	PokerPlayer::PartShow();
}

void BadDude::Set()
{
	std::string ln, fn;
	double draw;
	int nick;
	int poker{ rand() % 52 + 1 };

	std::cout << "Enter lastname: ";
	std::getline(std::cin, ln);
	std::cout << "Enter firstname: ";
	std::getline(std::cin, fn);
	std::cout << "Enter draw time: ";
	std::cin >> draw;
	std::cout << "Enter nicks: ";
	std::cin >> nick;

	*this = BadDude(ln, fn, draw, nick, poker);
}
