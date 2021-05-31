// studenti.h
// defining a Student class using private inheritance

#pragma once

#include <iostream>
#include <valarray>
#include <string>

class Student : private std::string, private std::valarray<double>
{
public:
	Student();
	explicit Student(const std::string& s);
	explicit Student(int n);
	Student(const std::string& s, int n);
	Student(const std::string& s, const std::valarray<double>& a);
	Student(const char* str, const double* pd, int n);
	~Student();

	double Average() const;
	const std::string& Name() const;

	double& operator[](int n);
	double operator[](int n) const;

	// friends
	// input
	// one word
	friend std::istream& operator>>(std::istream& is, Student& student);
	// one line
	friend std::istream& getline(std::istream& is, Student& student);
	// output
	friend std::ostream& operator<<(std::ostream& os, const Student& student);

private:
	// private method for scores output
	std::ostream& arr_out(std::ostream& os) const;
};
