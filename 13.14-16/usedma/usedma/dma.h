// dma.h
// inheritance and dynamic memory allocation

#pragma once

#include <iostream>

// Base Class using DMA
class baseDMA
{
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();

	baseDMA& operator=(const baseDMA& rs);
	
	friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);

private:
	char* label_;
	int rating_;
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public baseDMA
{
public:
	lacksDMA(const char* c = "blank", const char* l = "null",
		int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	virtual ~lacksDMA();

	friend std::ostream& operator<<(std::ostream& os, const lacksDMA& ls);

private:
	enum { COL_LEN = 40 };
	char color_[COL_LEN];
};

// derived class with DMA
class hasDMA : public baseDMA
{
public:
	hasDMA(const char* s = "none", const char* l = "null",
		int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& hs);
	virtual ~hasDMA();

	hasDMA& operator=(const hasDMA& hs);
	
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& hs);

private:
	char* style_;
};
