// tabtenn1.h
// a table-tennis base class

#pragma once

#include <string>

// simple base class
class TableTennisPlayer
{
public:
	TableTennisPlayer(const std::string& firstname = "none",
		const std::string& lastname = "none", bool hasTable = false);
	~TableTennisPlayer();

	void Name() const;
	bool HasTable() const;
	void ResetTable(bool v);

private:
	std::string firstname_;
	std::string lastname_;
	bool hasTable_;
};

// simple derived class
class RatedPlayer : public TableTennisPlayer
{
public:
	RatedPlayer(unsigned r, const std::string& firstname = "none",
		const std::string& lastname = "none", bool hasTable = false);
	RatedPlayer(unsigned r, const TableTennisPlayer& tp);
	~RatedPlayer();

	unsigned Rating() const;
	void ResetRating(unsigned r);

private:
	unsigned rating_;
};
