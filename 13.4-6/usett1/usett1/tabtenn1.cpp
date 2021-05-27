// tabtenn1.cpp
// simple base-class methods

#include <iostream>
#include "tabtenn1.h"

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

// RatePlayer methods
RatedPlayer::RatedPlayer(unsigned r, const std::string& firstname,
	const std::string& lastname, bool hasTable)
	: TableTennisPlayer(firstname, lastname, hasTable) {
	rating_ = r;
}

RatedPlayer::RatedPlayer(unsigned r, const TableTennisPlayer& tp)
	: TableTennisPlayer(tp), rating_(r) {

}

RatedPlayer::~RatedPlayer() {

}

unsigned RatedPlayer::Rating() const {
	return rating_;
}

void RatedPlayer::ResetRating(unsigned r) {
	rating_ = r;
}
