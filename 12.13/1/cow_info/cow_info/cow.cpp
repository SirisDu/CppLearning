// cow.cpp
// Cow class methods

#include <iostream>
#include <cstring>
#include "cow.h"

// default constructor
Cow::Cow() {
	name[0] = '\0';
	hobby = nullptr;
	weight = 0;
}

// constructor for initialization
Cow::Cow(const char* nm, const char* ho, double wt) {
	strcpy_s(name, 20, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy_s(hobby, strlen(ho) + 1, ho);
	weight = wt;
}

// copy constructor
Cow::Cow(const Cow& c) {
	strcpy_s(name, 20, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
}

// destructor
Cow::~Cow() {
	delete[] hobby;
}

// display all cow data
void Cow::ShowCow() const {
	std::cout << "cow name: " << name << std::endl;
	std::cout << "cow hobby: " << hobby << std::endl;
	std::cout << "cow weight: " << weight << std::endl;
}

// assignment overloaded
Cow& Cow::operator=(const Cow& c) {
	strcpy_s(name, 20, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;

	return *this;
}
