// pairs.h
// Pair class template

#pragma once

template <typename T1, typename T2>
class Pair
{
public:
	Pair() {}
	Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}
	virtual ~Pair() {}

	T1& first() { return a; }
	T2& second() { return b; }
	T1 first() const { return a; }
	T2 second() const { return b; }

private:
	T1 a;
	T2 b;
};
