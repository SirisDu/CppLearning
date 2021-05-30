// dma2.h
// inheritance and dynamic memory allocation

#pragma once

#include <iostream>

// Abstract Base Class using DMA
class baseABC
{
public:
	baseABC(const char* l = "null", int r = 0);
	baseABC(const baseABC& abc);
	virtual ~baseABC();

	virtual void View() const = 0;

	baseABC& operator=(const baseABC& abc);

protected:
	char* label_;
	int rating_;
};

// Base Class using DMA
class baseDMA : public baseABC
{
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();

	virtual void View() const;

	baseDMA& operator=(const baseDMA& rs);

private:

};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public baseABC
{
public:
	lacksDMA(const char* c = "blank", const char* l = "null",
		int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	virtual ~lacksDMA();

	virtual void View() const;

private:
	enum { COL_LEN = 40 };
	char color_[COL_LEN];
};

// derived class with DMA
class hasDMA : public baseABC
{
public:
	hasDMA(const char* s = "none", const char* l = "null",
		int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& hs);
	virtual ~hasDMA();

	virtual void View() const;

	hasDMA& operator=(const hasDMA& hs);

private:
	char* style_;
};
