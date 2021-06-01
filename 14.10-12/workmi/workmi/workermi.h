// workermi.h
// working classes with MI

#pragma once

#include <string>

class Worker                     // an abstract base class
{
public:
	Worker();
	Worker(const std::string& s, long n);
	virtual ~Worker() = 0;       // pure virtual destructor

	virtual void Set() = 0;
	virtual void Show() const = 0;

protected:
	virtual void Data() const;
	virtual void Get();

private:
	std::string fullname_;
	long id_;
};

class Waiter : virtual public Worker
{
public:
	Waiter();
	Waiter(const std::string& s, long n, int p = 0);
	Waiter(const Worker& wk, int p = 0);
	virtual ~Waiter();

	void Set();
	void Show() const;

protected:
	void Data() const;
	void Get();

private:
	int panache_;
};

class Singer : virtual public Worker
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

	void Data() const;
	void Get();

private:
	static const char* pv[Vtypes];  // string equivs of voice types
	int voice_;
};

// multiple inheritance
class SingerWaiter : public Singer, public Waiter
{
public:
	SingerWaiter();
	SingerWaiter(const std::string& s, long n, int p = 0, int v = other);
	SingerWaiter(const Worker& wk, int p = 0, int v = other);
	SingerWaiter(const Waiter& wt, int v = other);
	SingerWaiter(const Singer& wt, int p = 0);
	~SingerWaiter();

	void Set();
	void Show() const;

protected:
	void Data() const;
	void Get();

private:

};
