// studenti.cpp
// Student class using private inheritance

#include "studenti.h"

// constructors and destructor
// default constructor
Student::Student() : std::string("Null Student"), std::valarray<double>() {

}

Student::Student(const std::string& s)
	: std::string(s), std::valarray<double>() {

}

Student::Student(int n) : std::string("Nully"), std::valarray<double>(n) {

}

Student::Student(const std::string& s, int n)
	: std::string(s), std::valarray<double>(n) {

}

Student::Student(const std::string& s, const std::valarray<double>& a)
	: std::string(s), std::valarray<double>(a) {

}

Student::Student(const char* str, const double* pd, int n)
	: std::string(str), std::valarray<double>(pd, n) {

}

Student::~Student() {

}

// public methods
double Student::Average() const {
	if (std::valarray<double>::size() > 0)
	{
		return std::valarray<double>::sum() / std::valarray<double>::size();
	}
	else
	{
		return 0.0;
	}
}

const std::string& Student::Name() const {
	return (const std::string&)(*this);
}

double& Student::operator[](int n) {
	return std::valarray<double>::operator[](n);
}

double Student::operator[](int n) const {
	return std::valarray<double>::operator[](n);
}

// private method
std::ostream& Student::arr_out(std::ostream& os) const {
	int i{};
	size_t lim{ std::valarray<double>::size() };

	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << std::valarray<double>::operator[](i) << " ";
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
// use string version of operator>>()
std::istream& operator>>(std::istream& is, Student& student) {
	is >> (std::string&)student;

	return is;
}

// use string friend getline(istream&, const string&)
std::istream& getline(std::istream& is, Student& student)
{
	std::getline(is, (std::string&)student);

	return is;
}

// use string version of operator<<()
std::ostream& operator<<(std::ostream& os, const Student& student)
{
	os << "Scores for " << (const std::string&)student << ":" << std::endl;
	student.arr_out(os);           // use private method for scores

	return os;
}
