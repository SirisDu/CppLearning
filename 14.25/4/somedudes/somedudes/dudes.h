// dudes.h
// Person, Gunslinger, PokerPlayer, and BadDude classes

#pragma once

#include <string>

class Person
{
public:
	Person(const std::string& lastname = "None",
		const std::string& firstname = "Null")
		: lastname_(lastname), firstname_(firstname) {}
	virtual ~Person() {}

	virtual void Show() const;
	virtual void Set();

private:
	std::string lastname_;
	std::string firstname_;
};

class Gunslinger : virtual public Person
{
public:
	Gunslinger(const std::string& lastname = "None",
		const std::string& firstname = "Null",
		double draw = 0.0, int nick = 0) : Person(lastname, firstname),
		draw_(draw), nick_(nick) {}
	virtual ~Gunslinger() {}

	virtual void Show() const;
	virtual void PartShow() const;
	virtual double Draw() const { return draw_; }
	virtual void Set();

private:
	double draw_;
	int nick_;
};

class PokerPlayer : virtual public Person
{
public:
	PokerPlayer(const std::string& lastname = "None",
		const std::string& firstname = "Null", int poker = 1)
		: Person(lastname, firstname), poker_(poker) {}
	virtual ~PokerPlayer() {}

	virtual void Show() const;
	virtual void PartShow() const;
	virtual double Draw() const { return double(poker_); }
	virtual void Set();

private:
	int poker_;
};

class BadDude : virtual public Gunslinger, virtual public PokerPlayer
{
public:
	BadDude(const std::string& lastname = "None",
		const std::string& firstname = "Null", double draw = 0.0, int nick = 0,
		int poker = 1) : Person(lastname, firstname),
		Gunslinger(lastname, firstname, draw, nick),
		PokerPlayer(lastname, firstname, poker) {}
	~BadDude() {}

	void Show() const;
	void Gdraw() const { Gunslinger::Draw(); }
	void Cdraw() const { PokerPlayer::Draw(); }
	void Set();

private:

};
