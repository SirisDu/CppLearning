// tabtenn0.cpp
// simple base-class methods

#include <iostream>
#include "tabtenn0.h"

TableTennisPlayer::TableTennisPlayer(const std::string& firstname,
	const std::string& lastname, bool hasTable) :
	firstname_(firstname), lastname_(lastname), hasTable_(hasTable) {

}

TableTennisPlayer::~TableTennisPlayer() {

}

void TableTennisPlayer::Name() const {
	std::cout << lastname_ << ", " << firstname_;
}

bool TableTennisPlayer::HasTable() const {
	return hasTable_;
}

void TableTennisPlayer::ResetTable(bool v) {
	hasTable_ = v;
}
