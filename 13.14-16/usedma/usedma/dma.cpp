// dma.cpp
// dma class methods

#include "dma.h"

// baseDMA methods
baseDMA::baseDMA(const char* l, int r) {
	label_ = new char[strlen(l) + 1];
	strcpy_s(label_, strlen(l) + 1, l);
	rating_ = r;
}

baseDMA::baseDMA(const baseDMA& rs) {
	label_ = new char[strlen(rs.label_) + 1];
	strcpy_s(label_, strlen(rs.label_) + 1, rs.label_);
	rating_ = rs.rating_;
}

baseDMA::~baseDMA() {
	delete[] label_;
}

baseDMA& baseDMA::operator=(const baseDMA& rs) {
	if (this == &rs)
	{
		return *this;
	}

	delete[] label_;
	label_ = new char[strlen(rs.label_) + 1];
	strcpy_s(label_, strlen(rs.label_) + 1, rs.label_);
	rating_ = rs.rating_;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs) {
	os << "Label: " << rs.label_ << std::endl;
	os << "Rating: " << rs.rating_ << std::endl;

	return os;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char* c, const char* l, int r)
	: baseDMA(l, r) {
	strncpy_s(color_, c, COL_LEN - 1);
	color_[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char* c, const baseDMA& rs) : baseDMA(rs) {
	strncpy_s(color_, c, COL_LEN - 1);
	color_[COL_LEN - 1] = '\0';
}

lacksDMA::~lacksDMA() {

}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ls) {
	os << (const baseDMA&)ls;
	os << "Color: " << ls.color_ << std::endl;

	return os;
}

// hasDMA methods
hasDMA::hasDMA(const char* s, const char* l, int r) : baseDMA(l, r) {
	style_ = new char[strlen(s) + 1];
	strcpy_s(style_, strlen(s) + 1, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs) : baseDMA(rs) {
	style_ = new char[strlen(s) + 1];
	strcpy_s(style_, strlen(s) + 1, s);
}

hasDMA::hasDMA(const hasDMA& hs) : baseDMA(hs) {     // invoke base class copy constructor
	style_ = new char[strlen(hs.style_) + 1];
	strcpy_s(style_, strlen(hs.style_) + 1, hs.style_);
}

hasDMA::~hasDMA() {
	delete[] style_;
}

hasDMA& hasDMA::operator=(const hasDMA& hs) {
	if (this == &hs)
	{
		return *this;
	}

	baseDMA::operator=(hs);                          // copy base portion
	delete[] style_;                                 // prepare for new style
	style_ = new char[strlen(hs.style_) + 1];
	strcpy_s(style_, strlen(hs.style_) + 1, hs.style_);

	return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs) {
	os << (const baseDMA&)hs;
	os << "Style: " << hs.style_ << std::endl;

	return os;
}
