// stack.cpp
// Stack member functions

#include "stack.h"

// creates stack with n elements
Stack::Stack(int n) {
	size_ = n;
	top_ = 0;
	pitems_ = new Item[n];
}

// copy constructor
Stack::Stack(const Stack& st) {
	size_ = st.size_;
	top_ = st.top_;
	pitems_ = new Item[size_];
	for (int i = 0; i < top_; i++)
	{
		pitems_[i] = st.pitems_[i];
	}
}

Stack::~Stack() {
	delete[] pitems_;
}

bool Stack::isempty() const {
	return top_ == 0;
}

bool Stack::isfull() const {
	return top_ == size_;
}

// add item to stack
// push() returns false if stack already is full, true otherwise
bool Stack::push(const Item& item) {
	if (top_ < size_)
	{
		pitems_[top_++] = item;
		return true;
	}
	else
	{
		return false;
	}
}

// pop top into item
// pop() returns false if stack already is empty, true otherwise
bool Stack::pop(Item& item) {
	if (top_ > 0)
	{
		item = pitems_[--top_];
		return true;
	}
	else
	{
		return false;
	}
}

// assignment overloaded
Stack& Stack::operator=(const Stack& st) {
	if (this == &st)
	{
		return *this;
	}
	delete[] pitems_;
	size_ = st.size_;
	top_ = st.top_;
	pitems_ = new Item[size_];
	for (int i = 0; i < top_; i++)
	{
		pitems_[i] = st.pitems_[i];
	}

	return *this;
}
