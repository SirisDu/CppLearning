// dma2.cpp
// dma class methods

#include "dma2.h"

// baseABC methods
baseABC::baseABC(const char* l, int r) {
	size_t length{ strlen(l) };
	label_ = new char[length + 1];
	strcpy_s(label_, length + 1, l);
	rating_ = r;
}

baseABC::baseABC(const baseABC& abc) {
	size_t length{ strlen(abc.label_) };
	label_ = new char[length + 1];
	strcpy_s(label_, length + 1, abc.label_);
	rating_ = abc.rating_;
}

baseABC::~baseABC() {
	delete[] label_;
}

void baseABC::View() const {
	std::cout << " Label: " << label_ << std::endl;
	std::cout << "Rating: " << rating_ << std::endl;
}

baseABC& baseABC::operator=(const baseABC& abc) {
	if (this == &abc)
	{
		return *this;
	}
	else
	{
		delete[] label_;

		size_t length{ strlen(abc.label_) };

		label_ = new char[length + 1];
		rating_ = abc.rating_;

		return *this;
	}
}

// baseDMA methods
baseDMA::baseDMA(const char* l, int r) : baseABC(l, r) {

}

baseDMA::baseDMA(const baseDMA& rs) : baseABC(rs) {

}

baseDMA::~baseDMA() {
	
}

void baseDMA::View() const {
	baseABC::View();
}

baseDMA& baseDMA::operator=(const baseDMA& rs) {
	if (this == &rs)
	{
		return *this;
	}
	else
	{
		baseABC::operator=(rs);

		return *this;
	}
}

// lacksDMA methods
lacksDMA::lacksDMA(const char* c, const char* l, int r)
	: baseABC(l, r) {
	strncpy_s(color_, c, COL_LEN - 1);
	color_[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char* c, const baseDMA& rs) : baseABC(rs) {
	strncpy_s(color_, c, COL_LEN - 1);
	color_[COL_LEN - 1] = '\0';
}

lacksDMA::~lacksDMA() {

}

void lacksDMA::View() const {
	baseABC::View();
	std::cout << " Color: " << color_ << std::endl;
}

// hasDMA methods
hasDMA::hasDMA(const char* s, const char* l, int r) : baseABC(l, r) {
	style_ = new char[strlen(s) + 1];
	strcpy_s(style_, strlen(s) + 1, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs) : baseABC(rs) {
	style_ = new char[strlen(s) + 1];
	strcpy_s(style_, strlen(s) + 1, s);
}

// invoke base class copy constructor
hasDMA::hasDMA(const hasDMA& hs) : baseABC(hs) {
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

	baseABC::operator=(hs);                          // copy base portion
	delete[] style_;                                 // prepare for new style
	style_ = new char[strlen(hs.style_) + 1];
	strcpy_s(style_, strlen(hs.style_) + 1, hs.style_);

	return *this;
}

void hasDMA::View() const {
	baseABC::View();
	std::cout << " Style: " << style_ << std::endl;
}
