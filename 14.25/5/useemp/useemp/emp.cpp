// emp.cpp
// abstr_emp and children methods

#include "emp.h"

// abstr_emp methods
abstr_emp::abstr_emp()
{
	fname = "";
	lname = "";
	job = "";
}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln,
	const std::string& j) : fname(fn), lname(ln), job(j)
{

}

// labels and shows all data
void abstr_emp::ShowAll() const
{
	std::cout << "Name: " << fname << " " << lname << std::endl;
	std::cout << "Job: " << job << std::endl;
}

// prompts user for values
void abstr_emp::SetAll()
{
	std::cout << "Enter employee firstname: ";
	std::getline(std::cin, fname);
	std::cout << "Enter employee lastname: ";
	std::getline(std::cin, lname);
	std::cout << "Enter " << fname << " " << lname << "'s job: ";
	std::getline(std::cin, job);
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << e.fname << " " << e.lname;

	return os;
}

// employee methods
employee::employee() : abstr_emp()
{

}

employee::employee(const std::string& fn, const std::string& ln,
	const std::string& j) : abstr_emp(fn, ln, j)
{

}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "In charge of " << inchargeof << " employees" << std::endl;
}

// manager methods
manager::manager() : abstr_emp(), inchargeof(0)
{

}

manager::manager(const std::string& fn, const std::string& ln,
	const std::string& j, int ico)
	: abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico)
{

}

manager::manager(const manager& m) : abstr_emp(m), inchargeof(m.inchargeof)
{

}

void manager::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter the number of employees in charge of: ";
	std::cin >> inchargeof;
}

// fink methods
fink::fink() : abstr_emp(), reportsto("")
{

}

fink::fink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo)
{

}

fink::fink(const abstr_emp& e, const std::string& rpo)
	: abstr_emp(e), reportsto(rpo)
{

}

fink::fink(const fink& f) : abstr_emp(f), reportsto(f.reportsto)
{

}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "Whom this fink reports to: " << reportsto << std::endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter whom this fink reports to: ";
	std::getline(std::cin, reportsto);
}

// highfink methods
highfink::highfink() : abstr_emp(), manager(), fink()
{

}

highfink::highfink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{

}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, rpo)
{

}

highfink::highfink(const fink& f, int ico)
	: abstr_emp(f), manager(f, ico), fink(f)
{

}

highfink::highfink(const manager& m, const std::string& rpo)
	: abstr_emp(m), manager(m), fink(m, rpo)
{

}

highfink::highfink(const highfink& h)
	: abstr_emp(h), manager(h), fink(h)
{

}

void highfink::ShowAll() const
{
	manager::ShowAll();
	std::cout << "Whom this fink reports to: " << ReportTo() << std::endl;
}

void highfink::SetAll()
{
	manager::SetAll();
	std::cout << "Enter whom this fink reports to: ";
	std::getline(std::cin, ReportTo());
}
