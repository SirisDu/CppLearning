// emp.h
// header file for abstr_emp class and children

#pragma once

#include <iostream>
#include <string>

class abstr_emp
{
public:
	abstr_emp();
	abstr_emp(const std::string& fn, const std::string& ln,
		const std::string& j);
	virtual ~abstr_emp() = 0;       // virtual base class
	
	virtual void ShowAll() const;   // labels and shows all data
	virtual void SetAll();          // prompts user for values

	// just displays first and last name
	friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);

private:
	std::string fname;              // abstr_emp's first name
	std::string lname;              // abstr_emp's last name
	std::string job;
};

class employee : public abstr_emp
{
public:
	employee();
	employee(const std::string& fn, const std::string& ln,
		const std::string& j);

	virtual void ShowAll() const;
	virtual void SetAll();
};

class manager : virtual public abstr_emp
{
public:
	manager();
	manager(const std::string& fn, const std::string& ln,
		const std::string& j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);

	virtual void ShowAll() const;
	virtual void SetAll();

protected:
	int InChargeOf() const { return inchargeof; }   // output
	int& InChargeOf() { return inchargeof; }        // input

private:
	int inchargeof;                 // number of abstr_emps managed
};

class fink : virtual public abstr_emp
{
public:
	fink();
	fink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo);
	fink(const abstr_emp& e, const std::string& rpo);
	fink(const fink& f);

	virtual void ShowAll() const;
	virtual void SetAll();

protected:
	const std::string ReportTo() const { return reportsto; }
	std::string& ReportTo() { return reportsto; }

private:
	std::string reportsto;          // to whom fink reports
};

class highfink : public manager, public fink   // management fink
{
public:
	highfink();
	highfink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo, int ico);
	highfink(const abstr_emp& e, const std::string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const std::string& rpo);
	highfink(const highfink& h);

	virtual void ShowAll() const;
	virtual void SetAll();
};
