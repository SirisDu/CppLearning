// tabtenn0.h
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
