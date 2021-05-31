// worker0.h
// working classes

#pragma once

#include <string>

class Worker                     // an abstract base class
{
public:
	Worker();
	Worker(const std::string& s, long n);
	virtual ~Worker() = 0;       // pure virtual destructor

	virtual void Set();
	virtual void Show() const;

private:
	std::string fullname_;
	long id_;
};

class Waiter : public Worker
{
public:
	Waiter();
	Waiter(const std::string& s, long n, int p = 0);
	Waiter(const Worker& wk, int p = 0);
	virtual ~Waiter();

	void Set();
	void Show() const;

private:
	int panache_;
};

class Singer : public Worker
{
public:
	Singer();
	Singer(const std::string& s, long n, int v = other);
	Singer(const Worker& wk, int v = other);
	virtual ~Singer();

	void Set();
	void Show() const;

protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };

private:
	static const char* pv[Vtypes];  // string equivs of voice types
	int voice_;
};
