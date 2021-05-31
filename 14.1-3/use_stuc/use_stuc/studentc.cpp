// studentc.cpp
// Student class using containment

#include "studentc.h"

// public methods
Student::Student() : name_("Null Student"), scores_() {

}

Student::Student(const std::string& s) : name_(s), scores_() {

}

Student::Student(int n) : name_("Nully"), scores_(n) {

}

Student::Student(const std::string& s, int n) : name_(s), scores_(n) {

}

Student::Student(const std::string& s, const std::valarray<double>& a)
	: name_(s), scores_(a) {

}

Student::Student(const char* str, const double* pd, int n)
	: name_(str), scores_(pd, n) {

}

Student::~Student() {

}

double Student::Average() const {
	if (scores_.size() > 0)
	{
		return scores_.sum() / scores_.size();
	}
	else
	{
		return 0.0;
	}
}

const std::string& Student::Name() const {
	return name_;
}

double& Student::operator[](int n) {
	return scores_[n];              // use valarray<double>::operator[]{}
}

double Student::operator[](int n) const {
	return scores_[n];
}

// private method
std::ostream& Student::arr_out(std::ostream& os) const {
	int i{};
	size_t lim{ scores_.size() };

	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << scores_[i] << " ";
			if (i % 5 == 4)
			{
				os << std::endl;
			}
		}
		if (i % 5 != 0)
		{
			os << std::endl;
		}
	}
	else
	{
		os << " empty array ";
	}

	return os;
}

// friends
// use string version of operator>>
std::istream& operator>>(std::istream& is, Student& student) {
	is >> student.name_;

	return is;
}

// use string friend getline(std::istream& is, Student& student)
std::istream& getline(std::istream& is, Student& student) {
	std::getline(is, student.name_);

	return is;
}

// use string version of operator<<()
std::ostream& operator<<(std::ostream& os, const Student& student) {
	os << "Scores for " << student.name_ << ":" << std::endl;
	student.arr_out(os);            // use private method for scores

	return os;
}
